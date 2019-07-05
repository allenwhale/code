from __future__ import print_function


def dfs(i, j, dp):
    if dp[i][j] != -1:
        return dp[i][j]
    if j > i:
        return 0
    dp[i][j] = 0
    for k in range(1, j):
        dp[i][j] += dfs(i - j, k, dp)
    return dp[i][j]


def solution(n):
    dp = [list([-1 for __ in range(n + 1)]) for _ in range(n + 1)]
    for i in range(1, n + 1):
        dp[i][i] = 1
    ans = 0
    for i in range(1, n):
        ans += dfs(n, i, dp)
    return ans


if __name__ == "__main__":
    print(solution(3))
    print(solution(200))
