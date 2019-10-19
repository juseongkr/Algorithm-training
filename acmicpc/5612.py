n = int(input())
m = int(input())
r = m
for i in range(n):
    a, b = map(int, input().split())
    m += a
    m -= b
    if m < 0:
        print(0)
        exit()
    r = max(r, m)
print(r)
