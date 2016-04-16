import sys
def isprime(N):
    if N & 1 == 0: return 2
    i = 3
    cnt = 0
    while cnt < 1000:
        if N % i == 0: return i
        i += 2
        cnt += 1
    return -1
if __name__ == '__main__':
    T = input()
    [N, J] = input().split()
    N, J = int(N), int(J)
    cnt = 0
    for i in range(39, 2**(N-1)):
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
            if cnt >= J: break
