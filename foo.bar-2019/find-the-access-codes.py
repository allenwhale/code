from __future__ import print_function


def solution(l):
    ans = 0
    for j in range(1, len(l) - 1):
        cnti, cntk = 0, 0
        for i in range(0, j):
            if l[j] % l[i] == 0:
                cnti += 1
        for k in range(j + 1, len(l)):
            if l[k] % l[j] == 0:
                cntk += 1
        ans += cnti * cntk
    return ans


if __name__ == "__main__":
    print(solution([1, 1, 1]))
    print(solution([1, 2, 3, 4, 5, 6]))
    pass