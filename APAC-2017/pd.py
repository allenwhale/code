from random import randint
print("1")
print("5000 2")
l = [x for x in range(1, 5001)]
for _ in range(5):
    a, b = randint(0, 5000), randint(0, 5000)
    l[a], l[b] = l[b], l[a]
print(' '.join(str(x) for x in l))
