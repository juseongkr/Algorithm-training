n = int(input())
c, r = 1, 1
while True:
    if n >= c:
        n -= c
    else:
        c = 1
        n -= c
    if n == 0:
        break
    c += 1
    r += 1
print(r)
