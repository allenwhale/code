import random
T = 100
print(T)
for _ in range(T):
    N = 100
    P = random.randint(100000, 175000)
    print(N, P)
    for i in range(N):
        print(random.randint(200, 250), random.randint(240, 250))
