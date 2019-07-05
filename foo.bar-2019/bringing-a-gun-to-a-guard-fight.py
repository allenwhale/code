from __future__ import print_function
from collections import defaultdict
from itertools import product
import math


def gcd(a, b):
    a, b = abs(a), abs(b)
    while a != 0 and b != 0:
        a %= b
        if a == 0:
            break
        b %= a
        if b == 0:
            break
    return a + b


def fix(a, b):
    if a == 0 and b == 0:
        return 0, 0
    d = gcd(a, b)
    a //= d
    b //= d
    return a, b


def norm(a, b):
    return math.sqrt((a[0] - b[0])**2 + (a[1] - b[1])**2)


def get_indexes(sp, tp, dimensions, distance, idx):
    indexes = set()
    for j in range(2):
        cur = tp[idx]
        i = j
        while abs(sp[idx] - cur) <= distance:
            indexes.add(cur)
            if i == 0:
                cur = -cur
            else:
                cur = 2 * dimensions[idx] - cur
            i = 1 - i
    return indexes


def get_points(sp, tp, dimensions, distance):
    xs = get_indexes(sp, tp, dimensions, distance, 0)
    ys = get_indexes(sp, tp, dimensions, distance, 1)
    return list(filter(lambda x: norm(x, sp) <= distance, product(xs, ys)))


def get_dirs(sp, ps):
    dirs = defaultdict(lambda: 0x3f3f3f3f)
    for p in ps:
        v = fix(p[0] - sp[0], p[1] - sp[1])
        dirs[v] = min(dirs[v], norm(sp, p))
    return dirs


def solution(dimensions, your_position, guard_position, distance):
    gps = get_points(your_position, guard_position, dimensions, distance)
    yps = get_points(your_position, your_position, dimensions, distance)
    # print(gps, yps)
    gdirs = get_dirs(your_position, gps)
    ydirs = get_dirs(your_position, yps)
    # print(gdirs, ydirs)
    ans = 0
    for k in gdirs:
        if k not in ydirs:
            ans += 1
        else:
            if gdirs[k] < ydirs[k]:
                ans += 1
    return ans


if __name__ == "__main__":
    print(solution([3, 2], [1, 1], [2, 1], 4))
    print(solution([300, 275], [150, 150], [185, 100], 500))
    pass
