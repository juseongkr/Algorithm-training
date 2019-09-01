a, b = map(int, input().split())
for i in range(1, 1000):
    if a%i == 0 and b%i == 0:
        print("{} {} {}".format(i, a//i, b//i))
