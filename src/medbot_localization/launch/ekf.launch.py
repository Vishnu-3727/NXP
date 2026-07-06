"""M3: robot_localization EKF fusing wheel odom + IMU -> odom->base_footprint TF."""
import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    pkg = get_package_share_directory('medbot_localization')
    ekf_yaml = os.path.join(pkg, 'config', 'ekf.yaml')

    ekf_node = Node(
        package='robot_localization', executable='ekf_node', name='ekf_filter_node',
        output='screen', parameters=[ekf_yaml])

    return LaunchDescription([ekf_node])
