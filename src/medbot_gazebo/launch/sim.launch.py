"""M1 bring-up: Gazebo Harmonic + robot spawn + state publisher + ros_gz bridge
+ ros2_control controllers.

Sequencing (avoids the classic 'controller_manager not available' race):
  gz sim  ->  spawn robot (create)  ->  joint_state_broadcaster  ->  diff_drive_controller
"""
import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import (DeclareLaunchArgument, IncludeLaunchDescription,
                            RegisterEventHandler, SetEnvironmentVariable)
from launch.event_handlers import OnProcessExit
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import Command, LaunchConfiguration, PythonExpression
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue


def generate_launch_description():
    pkg_gazebo = get_package_share_directory('medbot_gazebo')
    pkg_desc = get_package_share_directory('medbot_description')
    pkg_ros_gz = get_package_share_directory('ros_gz_sim')

    xacro_file = os.path.join(pkg_desc, 'urdf', 'medbot.urdf.xacro')
    controllers_yaml = os.path.join(pkg_desc, 'config', 'controllers.yaml')
    bridge_yaml = os.path.join(pkg_gazebo, 'config', 'bridge.yaml')

    world = LaunchConfiguration('world')
    declare_world = DeclareLaunchArgument(
        'world', default_value=os.path.join(pkg_gazebo, 'worlds', 'empty.sdf'),
        description='Absolute path to the .sdf world to load')

    declare_headless = DeclareLaunchArgument(
        'headless', default_value='false',
        description='Run Gazebo server only (no GUI) — useful for testing/CI')
    headless_flag = PythonExpression(
        ["' -s --headless-rendering' if '", LaunchConfiguration('headless'),
         "' == 'true' else ''"])

    # ponytail: gz-sim doesn't resolve package:// mesh URIs on its own — it needs
    # each AMENT_PREFIX_PATH entry's share/ dir on GZ_SIM_RESOURCE_PATH, or meshes
    # silently fall back to a placeholder box (bit us adding rosbot_description meshes).
    gz_resource_path = SetEnvironmentVariable(
        name='GZ_SIM_RESOURCE_PATH',
        value=os.pathsep.join(
            os.path.join(p, 'share') for p in os.environ.get('AMENT_PREFIX_PATH', '').split(os.pathsep)))

    declare_x = DeclareLaunchArgument('x', default_value='0.0')
    declare_y = DeclareLaunchArgument('y', default_value='0.0')
    declare_yaw = DeclareLaunchArgument('yaw', default_value='0.0')

    # robot_description from xacro, passing the controllers.yaml path to the plugin.
    robot_description = ParameterValue(
        Command(['xacro ', xacro_file, ' controllers_config:=', controllers_yaml]),
        value_type=str)

    # Gazebo (server + gui). -r starts unpaused.
    gz_sim = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(pkg_ros_gz, 'launch', 'gz_sim.launch.py')),
        launch_arguments={'gz_args': [world, ' -r -v 4', headless_flag]}.items())

    robot_state_publisher = Node(
        package='robot_state_publisher', executable='robot_state_publisher',
        output='screen',
        parameters=[{'robot_description': robot_description, 'use_sim_time': True}])

    spawn_robot = Node(
        package='ros_gz_sim', executable='create', output='screen',
        arguments=['-topic', 'robot_description', '-name', 'medbot', '-z', '0.15',
                   '-x', LaunchConfiguration('x'), '-y', LaunchConfiguration('y'),
                   '-Y', LaunchConfiguration('yaw')])

    bridge = Node(
        package='ros_gz_bridge', executable='parameter_bridge', output='screen',
        parameters=[{'config_file': bridge_yaml, 'use_sim_time': True}])

    joint_state_broadcaster = Node(
        package='controller_manager', executable='spawner', output='screen',
        arguments=['joint_state_broadcaster', '--controller-manager', '/controller_manager'])

    diff_drive_controller = Node(
        package='controller_manager', executable='spawner', output='screen',
        arguments=['diff_drive_controller', '--controller-manager', '/controller_manager'])

    # Load controllers only after the robot (and its gz_ros2_control plugin) exists.
    load_jsb_after_spawn = RegisterEventHandler(
        OnProcessExit(target_action=spawn_robot, on_exit=[joint_state_broadcaster]))
    load_ddc_after_jsb = RegisterEventHandler(
        OnProcessExit(target_action=joint_state_broadcaster, on_exit=[diff_drive_controller]))

    return LaunchDescription([
        gz_resource_path,
        declare_world,
        declare_headless,
        declare_x,
        declare_y,
        declare_yaw,
        gz_sim,
        robot_state_publisher,
        bridge,
        spawn_robot,
        load_jsb_after_spawn,
        load_ddc_after_jsb,
    ])
