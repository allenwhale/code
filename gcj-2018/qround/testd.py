import math
from math import cos, sin

def rx(p, t):
    return (
            p[0],
            p[1] * cos(t) - p[2] * sin(t),
            p[1] * sin(t) + p[2] * cos(t)
            )

def ry(p, t):
    return (
            p[0] * cos(t) + p[2] * sin(t),
            p[1],
            -p[0] * sin(t) + p[2] * cos(t)
            )

def rz(p, t):
    return (
            p[0] * cos(t) - p[1] * sin(t),
            p[0] * sin(t) + p[1] * cos(t),
            p[2]
            )

def area(l):
    res = 0.
    for i in range(len(l)):
        res += l[i][0] * l[(i + 1) % len(l)][1]
    for i in range(len(l)):
        res -= l[i][1] * l[(i + 1) % len(l)][0]
    return abs(res) / 2.

# l = [
        # (.5, .5, .5),
        # (.5, -.5, .5),
        # (-.5, -.5, -.5),
        # (-.5, .5, -.5)
        # ]

# for x in l:
    # p = ry(x, -math.pi / 4)
    # print(x, '=>', p)
    # print(p[1], p[2])


l = [
        (.5, .5, .5),
        (.5, -.5, .5),
        (.5, -.5, -.5),
        (-.5, -.5, -.5),
        (-.5, .5, -.5),
        (-.5, .5, .5),
        ]

a = []

for x in l:
    p = ry(x, -math.pi / 4)
    # p = rz(p, -math.acos(math.sqrt(2 / 3)))
    print(x, '=>', p)
    # print((p[1], p[2]), math.sqrt(p[1] ** 2 + p[2] ** 2))
    # a.append((p[1], p[2]))

# print(area(a))

exit(0)


l = [.5, -.5]
for x in l:
    for y in l:
        for z in l:
            p = (x, y, z)
            pp = ry(rx(p, math.pi / 3), math.pi / 3)
            print(p, '=>', pp)
            print((pp[1], pp[2]))
