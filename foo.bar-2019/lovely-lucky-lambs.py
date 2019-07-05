from __future__ import print_function
import bisect
f = [1, 1]
for i in range(100):
    f.append(f[-1] + f[-2])
for i in range(1, len(f)):
    f[i] += f[i - 1]


def solution(total_lambs):
    mx = bisect.bisect_right(f, total_lambs)
    mn = 1
    while (2**(mn + 1)) - 1 <= total_lambs:
        mn += 1
    return mx - mn


if __name__ == "__main__":
    print(solution(143))
    print(solution(10))
