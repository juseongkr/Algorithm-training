e, f, c = map(int, input().split())
t, s = e + f, 0
while True:
    if t < c:
        break
    s += t//c
    t = t//c + t%c
print(s)
