# NXP Cup Rover — Session Status Report (2026-07-04)

## Goal this session
Move from a static M1 sim toward a navigating rover: bigger city world, more
roads, obstacle detection/avoidance, and (attempted) SLAM-based navigation.

## What got built, in order

1. **ROSbot XL mesh swap** (`medbot_description`) — replaced primitive
   box/cylinder geometry with the official `ros-jazzy-rosbot-description` mesh
   package. Fixed a `GZ_SIM_RESOURCE_PATH` bug that silently rendered meshes
   as placeholder boxes.
2. **City grid world** (`medbot_gazebo/worlds/city.sdf`) — rebuilt from a
   single cross intersection into a 3x3 road grid (4 parallel roads each
   direction, 16 intersections, ~16 buildings, hospitals/patient/signs
   repositioned to fit). Added extra static obstacles (barriers, parked cars,
   cones). Fixed a bug where the scripted "vehicle" actor's path ran straight
   through both hospital buildings (actors have no collision in Gazebo, so it
   was visibly clipping through them).
3. **M3 — SLAM mapping (medbot_localization): shelved, not resolved.**
   Built EKF (wheel odom + IMU yaw fusion) and SLAM Toolbox mapping. Fixed a
   lidar-rate bug (40Hz → 15Hz) that was overflowing SLAM's message filter.
   Despite that, every mapping attempt produced a corrupted, radiating-fan
   occupancy grid instead of clean walls — a sign of the robot's pose
   estimate drifting during the scan sequence. Tried both arc turns and pure
   pivot turns; both produced the same corruption. **Root cause was never
   actually found** — I hypothesized wheel slip on this 4-wheel rigid-axle
   base, but that's a guess, not a confirmed diagnosis. Abandoned the SLAM
   path rather than keep guessing blind (no RViz was used to actually watch
   the map build live, which is the standard way to debug this).
4. **Obstacle avoidance, take 1 — `nav2_collision_monitor`**
   (`medbot_control`). A LIDAR-based stop/slowdown safety layer sitting
   between a cmd_vel source and the wheels. Hit and fixed two real bugs:
   `enable_stamped_cmd_vel` needed to be set explicitly (message type
   mismatch silently dropped all commands), and it requires the `odom` TF
   frame to exist even with no map. Works, but is stop-only — it can't
   steer around an obstacle, only brake, so a robot that meets an obstacle
   head-on gets stuck permanently (confirmed by driving it into a wall).
5. **Obstacle avoidance, take 2 — local Nav2 controller** (new package
   `medbot_navigation`). Added `controller_server` (MPPI) with a rolling
   local costmap fed by LIDAR, plus a hand-written `wander_route` node that
   feeds it a hardcoded road-corridor path (no global planner/map). Hit and
   fixed the same `enable_stamped_cmd_vel` issue, a Python int/float bug in
   the path-building code, and a startup race where `controller_server`
   activated before EKF's first TF broadcast landed (needs EKF running and
   settled *first*).

## Current state — what's actually verified working

- Sim, EKF, `collision_monitor`, `local_nav` (MPPI), and `wander_route` all
  launch cleanly in the correct order and stay up.
- **Directly watched via screenshots** (not just logs/odometry) across two
  ~10-20s checks: the rover follows the road-corridor path and stays on
  pavement, rather than wandering onto grass as it did before a tuning fix.
- `collision_monitor` genuinely stops the robot at a LIDAR-detected obstacle
  (verified: odometry plateaus, confirmed via raw scan data it wasn't a false
  positive).

## What's still genuinely uncertain — the "something is wrong" concern

This is the honest list of things that were patched or worked around under
time pressure, not root-caused:

1. **Gazebo GUI died from an external `SIGINT` four separate times** during
   this session, always after a few minutes, never traced to a specific
   cause. User confirmed they weren't closing it. This could be a
   screensaver/idle/display-manager policy in this environment, or something
   else entirely. Every restart was a workaround, not a fix.
2. **SLAM mapping corruption was never root-caused**, only abandoned in favor
   of a map-free approach. If a global map/AMCL is needed later (e.g. for
   "go to hospital X"), this will need to be revisited properly — ideally
   with RViz live, or a human teleoperating with eyes on the map, since blind
   scripted driving turned out to be a bad way to debug this.
3. **The MPPI wandering-off-path fix was only spot-checked twice**, ~20s
   apart, over a short stretch of straight road. It has not been watched
   through an actual turn, an actual obstacle encounter, or a longer run. It
   may still have issues that a longer observation would reveal.
4. **The bring-up order is fragile and manual**: EKF must be launched and
   given time to publish its first TF before `local_nav` starts, or
   `controller_server` fails to activate outright. There is no single launch
   file that sequences this correctly yet — every test this session used
   manually staggered `sleep` calls between launches.
5. **No global path planning exists.** `wander_route` is a hardcoded loop
   through 4 intersections. There is no way yet to say "go to hospital A" —
   that needs either a working saved map + AMCL + global planner (blocked on
   item 2), or a different approach.
6. Wheel odometry drift on this 4-wheel rigid-axle chassis is real and
   confirmed (it's what broke SLAM, and what caused the MPPI wandering before
   EKF was added back in) but its magnitude/conditions were never
   characterized precisely — only observed indirectly through downstream
   symptoms.

## Files touched this session

- `medbot_description/`: base.xacro (mesh swap), sensors.xacro (lidar rate),
  config/controllers.yaml (odom TF ownership toggled twice)
- `medbot_gazebo/worlds/city.sdf`: full grid rebuild, obstacles, actor path fix
- `medbot_gazebo/launch/sim.launch.py`: GZ_SIM_RESOURCE_PATH fix
- `medbot_localization/`: config/ekf.yaml, config/slam_toolbox.yaml,
  launch/ekf.launch.py, launch/mapping.launch.py (SLAM path shelved but kept)
- `medbot_control/`: medbot_control/patrol_demo.py, config/collision_monitor.yaml,
  launch/collision_monitor.launch.py
- `medbot_navigation/` (new package): config/nav2_params.yaml,
  launch/local_nav.launch.py, medbot_navigation/wander_route.py
- `~/.local/bin/nxp-sim`, `~/.local/bin/nxp-drive` (shortcut commands)

## Suggested next step (not started)

Before building more on top of this: get RViz working so mapping/localization
issues can be diagnosed by watching, not guessing from logs. That would let
item 2 (SLAM corruption) actually get root-caused instead of routed around,
which is probably the real prerequisite for anything goal-directed rather
than a fixed wander loop.
