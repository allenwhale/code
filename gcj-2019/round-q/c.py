import math


def GCD(a, b):
    if a == b:
        return int(math.sqrt(a) + 0.1)
    while 1:
        a = a % b
        if not a:
            break
        b = b % a
        if not b:
            break
    return a + b


def Solve():
    [N, L] = list(map(int, input().strip().split()))
    C = list(map(int, input().strip().split()))
    P = [0] * (L+1)
    for i in range(L-1):
        if C[i] != C[i+1]:
            P[i+1] = math.gcd(C[i], C[i+1])
            for j in range(i, -1, -1):
                P[j] = C[j]//P[j+1]
            for j in range(i+2, L+1):
                P[j] = C[j-1]//P[j-1]
            break

    dP = sorted(set(P))
    for x in P:
        print(chr(ord('A')+dP.index(x)), end='')
    print()


T = int(input().strip())

for t in range(1, T+1):
    print("Case #%d: " % t, end='')
    Solve()
