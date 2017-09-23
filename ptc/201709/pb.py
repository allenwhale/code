T = int(input().strip())
for _ in range(T):
    s = set()
    data = input().split(',')
    for x in data:
        if x.find('~') != -1:
            [a, b] = x.split('~')
            for i in range(int(a), int(b) + 1):
                s.add(i)
        else:
            s.add(int(x.strip()))
    print(len(s), end=':')
    for x in sorted(s):
        print(' %d' % x, end='')
    print("")

