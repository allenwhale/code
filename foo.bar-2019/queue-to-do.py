from __future__ import print_function


def xor_range(a, b):
    def f(x):
        return [x, 1, x + 1, 0][x % 4]

    return f(b) ^ f(a - 1)


def solution(start, length):
    ans = 0
    for i in range(length):
        ans ^= xor_range(start + i * length,
                         start + i * length + length - i - 1)
        # for j in range(length - i):
        #     ans ^= start + i * length + j
    return ans


if __name__ == "__main__":
    print(solution(0, 3))
    print(solution(17, 4))
