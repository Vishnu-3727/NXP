# NXP Cup India 2026 - Autonomous Medical Response (MR-Buggy3, simulation)

ROS 2 and Gazebo stack for a rover that drives a city world using camera and LiDAR,
reaches a patient, and delivers them to a hospital. Built for the NXP Cup India 2026
Regional Round (simulation only).

## What works

| Package | Role |
|---|---|
| medbot_gazebo | City world (roads, hospital, obstacles), launch files, Gazebo bridge |
| medbot_description | Rover URDF with camera, LiDAR and IMU, controller config |
| medbot_localization | EKF and slam_toolbox, saved city map |
| medbot_navigation | Nav2 with Regulated Pure Pursuit, sequential road-waypoint goals, patient pickup and hospital delivery in goto_goal.py |
| medbot_control | Collision monitor and patrol demo |
| medbot_bringup | mission.launch.py runs simulation, EKF, Nav2, collision monitor and mission |

## Validation (see reports/)

- Full mission, patient pickup to hospital delivery: about 117 s of simulated time, 7 of 7 legs clean (headless and GUI).
- Obstacle avoidance with a barrier and a stalled car placed on the route: goal reached in 78 to 82 s, with swerves of about 0.9 m and a 3 m detour.

## Not implemented

- medbot_perception (road sign and patient detection) and medbot_behavior (mission state machine) are empty placeholders. Mission sequencing currently lives in medbot_navigation/goto_goal.py.
- Hospital choice from direction signs.
- Real-hardware run on the MR-Buggy3.

## Run

```
cd nxp_cup_ws
colcon build
source install/setup.bash
ros2 launch medbot_bringup mission.launch.py
```

Success marker in the log: `goal reached`, then `patient delivered`.
Before a run, kill any leftover Gazebo and Nav2 processes (stale processes cause false navigation failures).
