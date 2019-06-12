n = int(input())
f = int(input())
k = 0
n -= n % 100
while True:
    if (n + k) % f == 0:
        break
    k += 1
print("{0:02d}".format(k))
