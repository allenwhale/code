def Solve():
    [N, P] = map(int, input().strip().split())
    prefix = []
    for _ in range(P):
        prefix.append(input().strip())
    prefix = list(set(prefix))
    used_prefix = []
    for p1 in prefix:
        tf = True
        for p2 in prefix:
            if p1 != p2 and p1.startswith(p2):
                tf = False
        if tf:
            used_prefix.append(p1)
    ans = 1 << N
    for p in used_prefix:
        ans -= 1 << (N - len(p))
    return ans


T = int(input().strip())
for t in range(1, T + 1):
    print('Case #%d:' % t, Solve())
