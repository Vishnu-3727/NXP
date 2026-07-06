"""Guards the fix for the 'straight line across the grass' bug: densify must
emit points spaced ~step apart so MPPI's point-count look-ahead stays short."""
import math

from medbot_navigation.wander_route import densify, round_corners


def _max_corner_angle(pts):
    def ang(a, b, c):
        v1 = (b[0] - a[0], b[1] - a[1])
        v2 = (c[0] - b[0], c[1] - b[1])
        d = math.hypot(*v1) * math.hypot(*v2)
        if d == 0:
            return 0.0
        cs = max(-1.0, min(1.0, (v1[0]*v2[0] + v1[1]*v2[1]) / d))
        return math.degrees(math.acos(cs))
    return max(ang(pts[i], pts[i+1], pts[i+2]) for i in range(len(pts) - 2))


def test_round_corners_softens_right_angles():
    """A hard 90-deg corner is untrackable by MPPI (cuts it, then holds a ~1.3m
    off-line offset on the next leg). Rounding must soften every corner AND keep
    the endpoints (spawn / goal) exactly, or the goal_checker never fires."""
    square = [(0, 0), (0, 10), (10, 10), (10, 0)]
    r = round_corners(square, r=1.5, n=8)
    assert r[0] == square[0] and r[-1] == square[-1], 'endpoints moved'
    assert _max_corner_angle(square) > 89, 'baseline should be ~90 deg'
    assert _max_corner_angle(r) < 30, f'corner still sharp: {_max_corner_angle(r):.1f} deg'


def test_spacing_matches_step():
    pts = densify([(0, 0), (10, 0), (10, 10)], step=0.1)
    gaps = [math.hypot(x1 - x0, y1 - y0)
            for (x0, y0), (x1, y1) in zip(pts, pts[1:])]
    assert max(gaps) <= 0.1 + 1e-6, f'gap too large: {max(gaps)}'
    # 20m of path at 0.1m => ~200 segments; a coarse 1.0m path gave only ~20,
    # which is what turned MPPI's offset_from_furthest into a huge look-ahead.
    assert len(pts) >= 190, f'path too sparse: {len(pts)} points'


if __name__ == '__main__':
    test_spacing_matches_step()
    test_round_corners_softens_right_angles()
    print('OK')
