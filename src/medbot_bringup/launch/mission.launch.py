"""Full medbot bring-up in ONE launch: opens the Gazebo city world (GUI) AND
starts autonomous navigation. Composes the existing per-package launches:

  sim (world + robot + ros2_control + bridge)
    -> ekf            : wheel odom + IMU -> odom->base_footprint TF
    -> local_nav      : MPPI controller_server (FollowPath) -> cmd_vel_raw
    -> collision_mon  : cmd_vel_raw --LIDAR safety--> diff_drive_controller/cmd_vel
    -> wander_route   : feeds the hardcoded road-corridor path (delayed start)

Usage:  ros2 launch medbot_bringup mission.launch.py           # GUI
        ros2 launch medbot_bringup mission.launch.py headless:=true
"""
import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import (DeclareLaunchArgument, IncludeLaunchDescription,
                            TimerAction)
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    gz = get_package_share_directory('medbot_gazebo')
    loc = get_package_share_directory('medbot_localization')
    nav = get_package_share_directory('medbot_navigation')
    ctrl = get_package_share_directory('medbot_control')

    headless = DeclareLaunchArgument(
        'headless', default_value='false',
        description='true = Gazebo server only, no GUI (CI/testing)')
    goal_x = DeclareLaunchArgument('goal_x', default_value='2.0',
        description='world-frame goal X (default: patient pickup)')
    goal_y = DeclareLaunchArgument('goal_y', default_value='13.0',
        description='world-frame goal Y (default: patient pickup)')

    sim = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(gz, 'launch', 'sim.launch.py')),
        launch_arguments={'world': os.path.join(gz, 'worlds', 'city.sdf'),
                          # on the x=-7 road FACING NORTH (yaw=pi/2) so the first
                          # move is straight up the road; must match wander_route.SPAWN
                          'x': '-7.0', 'y': '0.0', 'yaw': '1.5708',
                          'headless': LaunchConfiguration('headless')}.items())

    ekf = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(loc, 'launch', 'ekf.launch.py')))

    local_nav = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(nav, 'launch', 'local_nav.launch.py')))

    collision_monitor = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(ctrl, 'launch', 'collision_monitor.launch.py')))

    # Stagger the nav2 lifecycle nodes ~6s after sim+ekf. Starting them at the same
    # instant as the sim makes the nav2 lifecycle_manager (autostart) try to
    # configure+ACTIVATE controller_server while (a) the odom->base_footprint TF
    # doesn't exist yet (gazebo's diff_drive controller isn't up until ~6s) so the
    # local_costmap activation races, and (b) the simultaneous DDS discovery storm
    # drops a lifecycle service response ("failed to send response") -> the
    # controller gets stuck in Configuring and never Activates (intermittent freeze:
    # rover sits at spawn, every FollowPath goal rejected "controller not active").
    # Delaying to a calmer, TF-ready window makes activation reliable.
    nav_stack = TimerAction(period=6.0, actions=[local_nav, collision_monitor])

    # 12s so bt_navigator is ACTIVE before goto_goal sends its first goal. goto_goal
    # also retries with backoff if it's still coming up, so this is a head-start,
    # not a hard requirement. spawn_* MUST match the sim spawn args above (the odom
    # frame originates at spawn); goal is the patient pickup at world (2,13).
    goto = TimerAction(period=12.0, actions=[
        Node(package='medbot_navigation', executable='goto_goal', output='screen',
             parameters=[{'spawn_x': -7.0, 'spawn_y': 0.0, 'spawn_yaw': 1.5708,
                          'goal_x': LaunchConfiguration('goal_x'),
                          'goal_y': LaunchConfiguration('goal_y'),
                          'use_sim_time': True}])])

    return LaunchDescription([headless, goal_x, goal_y, sim, ekf, nav_stack, goto])
