a, b, n = 0, 1, int(input())
for i in range(1, n):
    a, b = b, (a+b)%(10**9+7)
print(0 if n == 0 else b)
