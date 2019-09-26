a, b = map(int, input().split())
m = max(a, b)
for _ in range(int(input())):
    t = input()
    m = min(m, abs(b - int(t)))
m += 1
if abs(a-b) > m:
    print(m)
else:
    print(abs(a-b))
