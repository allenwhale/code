T = int(input())
for _ in range(T):
    N, W, H = map(lambda x: int(x), input().split())
    total = 0
    for i in range(N):
        total += int(input())
    print("YES" if total == W * H else "NO")
