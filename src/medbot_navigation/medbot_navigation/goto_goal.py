"""Drives the rover to the patient goal STAYING ON ROADS, by sequencing single
NavigateToPose goals through a short list of road-centreline waypoints.

NavFn has no road awareness -- to it grass and tarmac are identical free space,
so a single NavigateToPose to the patient cut a diagonal straight across the grass
(and through the central visual-sign cluster, where it stalled). Instead we drive
a short list of ROAD-CENTRELINE waypoints (like the old wander_route did): each leg
is a straight on-road segment, so NavFn's straight path stays on tarmac. The final
leg is a short approach across the grass to the patient (unavoidable -- the patient
at (2,14) sits inside a grass block ~6m from the nearest road). Nav2 still plans +
follows each leg and RE-PLANS around any obstacle it sees, so we keep obstacle
avoidance/rerouting.

We send the legs as SEQUENTIAL NavigateToPose goals (not one NavigateThroughPoses)
because single-pose NavigateToPose is the path already proven to drive reliably
here; each on-road leg is exactly that clean straight-goal case.

No map/AMCL: the EKF odom frame originates at spawn, so every world waypoint is
converted into odom via the same rigid spawn transform wander_route used.
"""
import math

import rclpy
from action_msgs.msg import GoalStatus
from geometry_msgs.msg import PoseStamped
from nav2_msgs.action import NavigateToPose
from rclpy.action import ActionClient
from rclpy.node import Node

# Road grid: tarmac only at x,y in these values (each 4m wide); everything else is
# grass. Staging waypoints MUST lie on a centreline (guarded by test).
ROAD_COORDS = {-21.0, -7.0, 7.0, 21.0}

# Patient-pickup road route (world frame), spawn at (-7,0) facing north:
#   (-7,7)  -- north up the x=-7 road to the y=7 intersection
#   (2,7)   -- east along the y=7 road to the staging point below the patient
# then the final goal (default patient (2,13)) is appended: a ~6m straight
# approach north across the grass block to the patient. Only this last leg is off
# road, and it has to be (the patient is not on a road).
ROAD_WAYPOINTS = [(-7.0, 7.0), (2.0, 7.0)]


def world_to_odom(wx, wy, spawn):
    """Map a world point into the odom frame. The EKF odom frame originates at the
    spawn pose and is rotated by the spawn yaw, so this is a rigid transform, not
    just an offset. (Same transform wander_route uses; spawn passed in so it works
    for any spawn pose.)"""
    sx, sy, syaw = spawn
    dx, dy = wx - sx, wy - sy
    c, s = math.cos(syaw), math.sin(syaw)
    return (dx * c + dy * s, -dx * s + dy * c)


class GotoGoal(Node):
    def __init__(self):
        super().__init__('goto_goal')
        self.declare_parameter('spawn_x', -7.0)
        self.declare_parameter('spawn_y', 0.0)
        self.declare_parameter('spawn_yaw', math.pi / 2)
        self.declare_parameter('goal_x', 2.0)
        self.declare_parameter('goal_y', 13.0)
        spawn = (self.get_parameter('spawn_x').value,
                 self.get_parameter('spawn_y').value,
                 self.get_parameter('spawn_yaw').value)
        gx = self.get_parameter('goal_x').value
        gy = self.get_parameter('goal_y').value
        route_world = ROAD_WAYPOINTS + [(gx, gy)]
        self.route_odom = [world_to_odom(x, y, spawn) for x, y in route_world]
        self.idx = 0
        self.get_logger().info(
            f'route world {route_world} -> odom {self.route_odom}, spawn {spawn}')

        self.client = ActionClient(self, NavigateToPose, 'navigate_to_pose')
        self.send_goal()

    def build_goal(self):
        x, y = self.route_odom[self.idx]
        goal = NavigateToPose.Goal()
        pose = PoseStamped()
        pose.header.frame_id = 'odom'
        pose.header.stamp = self.get_clock().now().to_msg()
        pose.pose.position.x = float(x)
        pose.pose.position.y = float(y)
        pose.pose.orientation.w = 1.0   # heading irrelevant (wide yaw tolerance)
        goal.pose = pose
        return goal

    def send_goal(self):
        self.client.wait_for_server()
        self.get_logger().info(f'-> leg {self.idx + 1}/{len(self.route_odom)} '
                               f'to odom {self.route_odom[self.idx]}')
        future = self.client.send_goal_async(self.build_goal())
        future.add_done_callback(self.on_goal_response)

    def retry_after(self, delay=2.0):
        """One-shot backoff before re-sending. bt_navigator advertises its action
        server before it is ACTIVE (nav2 autostart lifecycle), so wait_for_server
        passes yet the goal is rejected; retrying immediately hot-loops until it
        activates. A 2s pause makes a slow (GUI) start-up harmless. (Same guard as
        wander_route.)"""
        self._retry_timer = self.create_timer(delay, self._retry_fire)

    def _retry_fire(self):
        self._retry_timer.cancel()
        self.destroy_timer(self._retry_timer)
        self.send_goal()

    def on_goal_response(self, future):
        handle = future.result()
        if not handle.accepted:
            self.get_logger().warn('goal rejected (bt_navigator not active yet), backing off 2s')
            self.retry_after(2.0)
            return
        handle.get_result_async().add_done_callback(self.on_result)

    def on_result(self, future):
        status = future.result().status
        if status == GoalStatus.STATUS_SUCCEEDED:
            self.idx += 1
            if self.idx >= len(self.route_odom):
                self.get_logger().info('goal reached')   # verify: assert on this log line
                return
            self.get_logger().info(f'leg done, advancing to leg {self.idx + 1}')
            self.retry_after(0.3)   # brief settle, then next leg
            return
        # leg aborted/failed -- retry the SAME leg after a short pause.
        self.get_logger().warn(f'leg {self.idx + 1} ended status {status}, retrying in 3s')
        self.retry_after(3.0)


def main():
    rclpy.init()
    node = GotoGoal()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
