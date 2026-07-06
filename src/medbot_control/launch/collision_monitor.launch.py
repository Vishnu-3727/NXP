"""nav2_collision_monitor: stops/slows cmd_vel_raw -> diff_drive_controller/cmd_vel
based on live LIDAR data. No map/AMCL required -- the official Nav2 replacement
for the plan's 'safety_stop' node."""
import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    pkg = get_package_share_directory('medbot_control')
    params = os.path.join(pkg, 'config', 'collision_monitor.yaml')

    lifecycle_manager = Node(
        package='nav2_lifecycle_manager', executable='lifecycle_manager',
        name='lifecycle_manager_collision_monitor', output='screen',
        parameters=[{'autostart': True, 'node_names': ['collision_monitor'],
                     'use_sim_time': True}])

    collision_monitor = Node(
        package='nav2_collision_monitor', executable='collision_monitor',
        output='screen', parameters=[params])

    return LaunchDescription([lifecycle_manager, collision_monitor])
