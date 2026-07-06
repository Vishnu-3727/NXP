from glob import glob
from setuptools import find_packages, setup

package_name = 'medbot_navigation'

setup(
    name=package_name,
    version='0.1.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob('launch/*.py')),
        ('share/' + package_name + '/config', glob('config/*')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='vishnu',
    maintainer_email='vishnuvardhanks113@gmail.com',
    description='Nav2 local controller and road-route wander node for the rover.',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'wander_route = medbot_navigation.wander_route:main',
            'goto_goal = medbot_navigation.goto_goal:main',
        ],
    },
)
