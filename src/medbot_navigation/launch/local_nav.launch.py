"""M4 (local-only): Nav2 controller_server (MPPI) with a rolling local costmap
fed by LIDAR, for real obstacle-avoiding trajectory following. No map/AMCL --
wander_route.py feeds it a hardcoded road-corridor path. Output remapped to
cmd_vel_raw so collision_monitor stays downstream as a safety backstop."""
import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    pkg = get_package_share_directory('medbot_navigation')
    params = os.path.join(pkg, 'config', 'nav2_params.yaml')

    controller_server = Node(
        package='nav2_controller', executable='controller_server',
        output='screen', parameters=[params],
        remappings=[('cmd_vel', 'cmd_vel_raw')])

    # Global planning half: NavFn plans around obstacles, bt_navigator drives the
    # plan and re-plans when the lidar reveals a new one, behavior_server recovers
    # when stuck. behavior_server's recovery cmd_vel also goes through the
    # collision_monitor (remapped to cmd_vel_raw, like the controller).
    planner_server = Node(
        package='nav2_planner', executable='planner_server',
        output='screen', parameters=[params])

    behavior_server = Node(
        package='nav2_behaviors', executable='behavior_server',
        output='screen', parameters=[params],
        remappings=[('cmd_vel', 'cmd_vel_raw')])

    bt_navigator = Node(
        package='nav2_bt_navigator', executable='bt_navigator',
        output='screen', parameters=[params])

    # bt_navigator activates LAST -- it depends on planner/controller/behavior
    # servers already being ACTIVE.
    lifecycle_manager = Node(
        package='nav2_lifecycle_manager', executable='lifecycle_manager',
        name='lifecycle_manager_navigation', output='screen',
        parameters=[{'autostart': True,
                     'node_names': ['controller_server', 'planner_server',
                                    'behavior_server', 'bt_navigator'],
                     'use_sim_time': True}])

    return LaunchDescription([controller_server, planner_server,
                              behavior_server, bt_navigator, lifecycle_manager])
