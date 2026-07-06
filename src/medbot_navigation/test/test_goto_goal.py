"""Guards the world->odom goal transform: a goal given in world coords must land
at the correct odom coords for the actual spawn pose, or NavigateToPose sends the
rover to the wrong place. Mirrors test_densify's plain-pytest style."""
import math

from medbot_navigation.goto_goal import world_to_odom, ROAD_WAYPOINTS, ROAD_COORDS


def test_staging_waypoints_are_on_road_centrelines():
    # Each staging waypoint must sit on a road (x or y on a centreline), or the
    # route drives on grass -- the whole point of the road route. The final goal
    # (patient) is appended separately and is allowed off-road.
    for x, y in ROAD_WAYPOINTS:
        assert x in ROAD_COORDS or y in ROAD_COORDS, f'waypoint ({x},{y}) is off-road'


def test_goal_at_spawn_maps_to_origin():
    # The spawn itself is the odom origin, whatever the yaw.
    x, y = world_to_odom(-7.0, 0.0, (-7.0, 0.0, math.pi / 2))
    assert abs(x) < 1e-9 and abs(y) < 1e-9


def test_north_of_spawn_facing_north_is_straight_ahead():
    # Spawn at (-7,0) facing north (+y world = forward). Goal 13m north at (-7,13)
    # must be straight ahead in odom: +x (forward), 0 lateral.
    x, y = world_to_odom(-7.0, 13.0, (-7.0, 0.0, math.pi / 2))
    assert abs(x - 13.0) < 1e-6, f'forward wrong: {x}'
    assert abs(y) < 1e-6, f'should be dead ahead: {y}'


def test_patient_goal_is_forward_and_right():
    # Real demo: spawn (-7,0,pi/2) -> patient goal world (2,13). World it's
    # +9 east, +13 north. Facing north, north=forward(+x), east=right(-y in ROS).
    x, y = world_to_odom(2.0, 13.0, (-7.0, 0.0, math.pi / 2))
    assert abs(x - 13.0) < 1e-6, f'forward: {x}'
    assert abs(y - (-9.0)) < 1e-6, f'lateral (east=right=-y): {y}'
    # distance preserved by the rigid transform
    assert abs(math.hypot(x, y) - math.hypot(9.0, 13.0)) < 1e-6


if __name__ == '__main__':
    test_staging_waypoints_are_on_road_centrelines()
    test_goal_at_spawn_maps_to_origin()
    test_north_of_spawn_facing_north_is_straight_ahead()
    test_patient_goal_is_forward_and_right()
    print('OK')
