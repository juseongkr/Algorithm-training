n, m, l = map(int, input().split())
d = [0]*1001
c, r = 0, 0
while True:
    d[c] += 1
    if d[c] == m:
        break
    if d[c] % 2 == 1:
        c = (c + n - l) % n
    else:
        c = (c + l) % n
    r += 1
print(r)
