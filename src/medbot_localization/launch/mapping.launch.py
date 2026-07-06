"""M3: SLAM Toolbox online-async mapping. Thin wrapper over slam_toolbox's own
launch file with our frame/topic-tuned params file."""
import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource


def generate_launch_description():
    pkg = get_package_share_directory('medbot_localization')
    pkg_slam = get_package_share_directory('slam_toolbox')
    slam_params = os.path.join(pkg, 'config', 'slam_toolbox.yaml')

    slam = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_slam, 'launch', 'online_async_launch.py')),
        launch_arguments={'slam_params_file': slam_params}.items())

    return LaunchDescription([slam])
