"""Feeds controller_server's FollowPath action a hardcoded loop through the
city grid's road corridors (spawn -> centre -> 4 nearby intersections -> back).
The path itself never touches a building; MPPI's local costmap handles
swerving around whatever LIDAR sees along the way (barriers, parked cars,
cones, pedestrians, the vehicle actor). No map/AMCL/global planner --
this is a known-safe route, not a general-purpose planner.
"""
import math

import rclpy
from action_msgs.msg import GoalStatus
from geometry_msgs.msg import PoseStamped
from nav2_msgs.action import FollowPath
from nav_msgs.msg import Path
from rclpy.action import ActionClient
from rclpy.node import Node

# Spawn pose in the WORLD (MUST match mission.launch.py's spawn args). The rover
# sits on the x=-7 north-south road FACING NORTH (yaw=pi/2) so its first move is
# straight up the road. Spawning it facing east (yaw=0) pointed it straight ACROSS
# the road into the grass; MPPI could not make that 90-deg standing turn onto the
# road and just idled near spawn.
SPAWN = (-7.0, 0.0, math.pi / 2)   # (x, y, yaw), world frame

# Road-only waypoints. city.sdf ONLY has road at x,y in {-21,-7,7,21} (each 4m
# wide); the centre block around (0,0) is GRASS (painted lane lines, no road).
# Every segment stays on a real road centreline (x=-7 up, y=7 across, x=7 down,
# y=-7 back). OPEN perimeter lap, not a closed loop: FollowPath's goal_checker
# (xy_goal_tolerance 0.4m) fires near the path's LAST point, so the endpoint must
# sit far from spawn (ending back at spawn made the goal read as reached at t=0).
# Single lap for now; continuous patrol is a follow-up.
WORLD_WAYPOINTS = [
    (-7, 0), (-7, 7), (7, 7), (7, -7), (-7, -7),
]


def world_to_odom(wx, wy):
    """Map a world point into the odom frame. The EKF's odom frame originates at
    the spawn pose and is rotated by the spawn yaw, so this is a rigid transform,
    not just an offset (the old +8 shortcut only worked when spawn yaw was 0)."""
    sx, sy, syaw = SPAWN
    dx, dy = wx - sx, wy - sy
    c, s = math.cos(syaw), math.sin(syaw)
    return (dx * c + dy * s, -dx * s + dy * c)


def round_corners(points, r=1.5, n=8):
    """Replace each interior 90-deg vertex with a quadratic Bezier so the path
    curves through the intersection instead of demanding an instant right-angle.

    A hard corner is untrackable for a look-ahead controller: a far align
    look-ahead (offset_from_furthest 20 = 2m) cuts the corner and then holds a
    ~1.3m off-line equilibrium on the next leg; a short one stalls MPPI
    ('Failed to make progress'). Rounding fixes it at the path source -- the
    2m look-ahead now has a feasible curve to align to. r stays < half the
    shortest edge and < the 2m road half-width, so the arc never leaves tarmac.
    ponytail: geometry at the path source beats threading the critic offset.
    """
    if len(points) < 3:
        return points
    out = [points[0]]
    for a, v, b in zip(points, points[1:], points[2:]):
        din = _unit(v[0] - a[0], v[1] - a[1])
        dout = _unit(b[0] - v[0], b[1] - v[1])
        ri = min(r, math.hypot(v[0]-a[0], v[1]-a[1]) / 2,
                 math.hypot(b[0]-v[0], b[1]-v[1]) / 2)
        entry = (v[0] - din[0]*ri, v[1] - din[1]*ri)
        exit_ = (v[0] + dout[0]*ri, v[1] + dout[1]*ri)
        for i in range(n + 1):
            t = i / n
            mt = 1 - t
            out.append((mt*mt*entry[0] + 2*mt*t*v[0] + t*t*exit_[0],
                        mt*mt*entry[1] + 2*mt*t*v[1] + t*t*exit_[1]))
    out.append(points[-1])
    return out


def _unit(dx, dy):
    d = math.hypot(dx, dy) or 1.0
    return (dx / d, dy / d)


def densify(points, step=0.1):
    """Linearly interpolate so consecutive path points are ~step apart.

    step MUST stay small (~costmap resolution). MPPI's PathAlign/PathFollow/
    PathAngle critics measure look-ahead in *path-point counts*, not metres
    (offset_from_furthest: 20/5/4). A coarse path (e.g. 1.0m) turns those into
    a 20m/5m look-ahead, so MPPI beelines diagonally to a far point and cuts
    across the grass instead of tracking the road corridor.
    ponytail: fixes look-ahead at the path source, not by re-tuning 4 critics.
    """
    dense = [points[0]]
    for (x0, y0), (x1, y1) in zip(points, points[1:]):
        dist = math.hypot(x1 - x0, y1 - y0)
        n = max(1, int(dist / step))
        for i in range(1, n + 1):
            t = i / n
            dense.append((x0 + (x1 - x0) * t, y0 + (y1 - y0) * t))
    return dense


class WanderRoute(Node):
    def __init__(self):
        super().__init__('wander_route')
        self.client = ActionClient(self, FollowPath, 'follow_path')
        odom_points = [world_to_odom(x, y) for x, y in WORLD_WAYPOINTS]
        self.dense_points = densify(round_corners(odom_points), step=0.1)
        self.get_logger().info(f'{len(self.dense_points)} path points, looping')
        self.send_loop()

    def build_path(self):
        path = Path()
        path.header.frame_id = 'odom'
        path.header.stamp = self.get_clock().now().to_msg()
        for x, y in self.dense_points:
            pose = PoseStamped()
            pose.header.frame_id = 'odom'
            pose.pose.position.x = float(x)
            pose.pose.position.y = float(y)
            pose.pose.orientation.w = 1.0
            path.poses.append(pose)
        return path

    def send_loop(self):
        self.client.wait_for_server()
        goal = FollowPath.Goal()
        goal.path = self.build_path()
        future = self.client.send_goal_async(goal)
        future.add_done_callback(self.on_goal_response)

    def retry_after(self, delay=2.0):
        """One-shot backoff before re-sending. Retrying immediately hot-loops at
        ~120 goals/s while controller_server is still activating (nav2 autostart
        lifecycle) -- the server advertises but rejects every goal, so wait_for_server
        passes yet goals are rejected/aborted, and the flood (10k+ status-6 aborts)
        stops the stack from ever recovering. A 2s pause makes a slow (GUI) start-up
        harmless: it just retries politely until the controller is ACTIVE and accepts.
        ponytail: one guard in the retry path fixes the whole race; no launch re-arch."""
        self._retry_timer = self.create_timer(delay, self._retry_fire)

    def _retry_fire(self):
        self._retry_timer.cancel()          # one-shot: fire once, then stop
        self.destroy_timer(self._retry_timer)
        self.send_loop()

    def on_goal_response(self, future):
        handle = future.result()
        if not handle.accepted:
            # REJECTED = controller_server not ACTIVE yet (nav2 autostart still
            # bringing up the lifecycle). Back off 2s so we don't hot-loop at
            # ~120 goals/s while it activates -- this is the startup-flood guard.
            self.get_logger().warn('FollowPath goal rejected (controller not active), backing off 2s')
            self.retry_after(2.0)
            return
        result_future = handle.get_result_async()
        result_future.add_done_callback(self.on_result)

    def on_result(self, future):
        # Goal was ACCEPTED and ran, then ended (success, or status-6 progress
        # abort mid-drive). Retry almost immediately: a running goal takes seconds
        # to end so this can't flood, and a long dead pause here would restart
        # MPPI's optimizer from a dead stop every abort -- which stalls it at
        # corners (it can't re-converge a turning trajectory from rest in one
        # iteration). Fast retry keeps control continuous, like the pre-backoff loop.
        status = future.result().status
        if status != GoalStatus.STATUS_SUCCEEDED:
            self.get_logger().warn(f'FollowPath ended with status {status}, resending')
        else:
            self.get_logger().info('loop complete, restarting')
        self.retry_after(0.3)


def main():
    rclpy.init()
    node = WanderRoute()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
