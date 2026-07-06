"""Drives the rover in a repeating loop through the city grid's blocks, for
demo/visual verification before Nav2 (M4) exists. Publishes TwistStamped
cmd_vel on a timer-driven phase sequence -- no perception, no planning.
"""
import rclpy
from geometry_msgs.msg import TwistStamped
from rclpy.node import Node

# (linear_x, angular_z, duration_s) -- one loop drives a block, turns, repeats.
PHASES = [
    (0.4, 0.0, 6.0),
    (0.2, 0.5, 3.0),
    (0.4, 0.0, 6.0),
    (0.2, 0.5, 3.0),
    (0.4, 0.0, 6.0),
    (0.2, 0.5, 3.0),
    (0.4, 0.0, 6.0),
    (0.2, 0.5, 3.0),
]


class PatrolDemo(Node):
    def __init__(self):
        super().__init__('patrol_demo')
        # Publishes to the raw/candidate topic -- nav2_collision_monitor
        # (medbot_control/collision_monitor.launch.py) sits downstream and
        # stops/slows this before it reaches diff_drive_controller/cmd_vel.
        self.pub = self.create_publisher(TwistStamped, '/cmd_vel_raw', 10)
        self.phase_idx = 0
        self.phase_elapsed = 0.0
        self.period = 0.05
        self.timer = self.create_timer(self.period, self.tick)

    def tick(self):
        linear_x, angular_z, duration = PHASES[self.phase_idx]
        msg = TwistStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'base_footprint'
        msg.twist.linear.x = linear_x
        msg.twist.angular.z = angular_z
        self.pub.publish(msg)

        self.phase_elapsed += self.period
        if self.phase_elapsed >= duration:
            self.phase_elapsed = 0.0
            self.phase_idx = (self.phase_idx + 1) % len(PHASES)
            self.get_logger().info(f'phase -> {self.phase_idx}')


def main():
    rclpy.init()
    node = PatrolDemo()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
