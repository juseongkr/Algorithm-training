s, t = 0, 0
for _ in range(10):
    a, b = map(int, input().split())
    t += (b-a)
    s = max(s, t)
print(s)
