C = [1]
for i in range(1, 5010):
    C.append((C[-1] * 2 * (2 * i + 1)) // (i + 2))
C = [1] + C
n = int(input().strip())
ans = 0
for i in range(n + 1):
    ans += C[i] * C[n - i]
print(ans)
