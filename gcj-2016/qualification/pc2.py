import sys
def isprime(N):
    if N & 1 == 0: return 2
    i = 3
    while i * i <= N:
        if N % i == 0: return i
        i += 2
    return -1
if __name__ == '__main__':
    T = input()
    [N, J] = input().split()
    N, J = int(N), int(J)
    cnt = 0
    for i in range(2**(N-1)-2, 0, -1):
        if i & 1 == 0: continue
        raw = '1' + bin(i)[2:].zfill(N - 1)
        tf = True
        ans = []
        for b in range(2, 11):
            f = isprime(int(raw, b))
            if f == -1:
                tf = False
                break
            else:
                ans.append(str(f))
        if tf:
            sys.stderr.write('%s %s\n'%(raw, ' '.join(ans)))
            print('%s %s'%(raw, ' '.join(ans)))
            cnt += 1
            if cnt == J: break
