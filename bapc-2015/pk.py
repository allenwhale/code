import random
N = 12
M = 30
print(100)
for _ in range(100):
    print(N, M)
    for i in range(N):
        print(bin(random.randint(0, 1<<M))[2:].zfill(M), random.randint(0, M))
