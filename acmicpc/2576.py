s, m = 0, 101
for i in range(7):
    n = int(input())
    if n%2 != 0:
        s += n
        m = min(m, n)
if s:
    print(s)
    print(m)
else:
    print("-1")
