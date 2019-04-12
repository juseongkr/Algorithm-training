from bisect import *
input()
s, l , r = 0, [], []
n = [*map(int, input().split())]
for i in range(len(n)):
    it = bisect_left(n, n[i], 0, s)
    if it == s:
        s += 1
    n[it] = n[i]
    l.append([it, n[i]])
print(s)
for i in l[::-1]:
    if i[0] == s-1:
        r.append(i[1])
        s -= 1
for i in r[::-1]:
    print(i, end=' ')
