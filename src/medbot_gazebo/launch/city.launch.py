"""Launch the full sim in the M2 city world with the rover on the west road arm
facing the intersection. Thin wrapper over sim.launch.py."""
import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource


def generate_launch_description():
    pkg_gazebo = get_package_share_directory('medbot_gazebo')
    city = os.path.join(pkg_gazebo, 'worlds', 'city.sdf')

    sim = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(pkg_gazebo, 'launch', 'sim.launch.py')),
        launch_arguments={
            'world': city,
            'x': '-8.0', 'y': '0.0', 'yaw': '0.0',   # on west arm, facing east
        }.items())

    return LaunchDescription([sim])
