import sys
sys.setrecursionlimit(10000)
_f = {}
def f(x):
    if x in _f: return _f[x]
    _f[x] = 1 if x <= 1 else x * f(x - 1)
    return _f[x]

def make2d(n, m):
    res = []
    for _ in range(n):
        res.append([0 for __ in range(m)])
    return res

def Solve():
    N, M = [int(x) for x in input().split()]
    dp = make2d(N + 1, M + 1)
    for i in range(N + 1):
        dp[i][0] = 1
    for i in range(1, N + 1):
        for j in range(1, min(i, M + 1)):
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
    can = dp[N][M] * f(N) * f(M)
    return can / f(N + M)

T = int(input())
for i in range(T):
    print('Case #%d: %.7f' % (i + 1, Solve()))
