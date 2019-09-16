while True:
    n = int(input())
    if n == 0:
        break
    m, l = {}, []
    for _ in range(n):
        s = input()
        t = s.lower()
        l.append(t)
        m[t] = s
    l.sort()
    print(m[l[0]])
