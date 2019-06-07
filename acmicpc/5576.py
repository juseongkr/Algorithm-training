a, b = [], []
for _ in range(10):
    a.append(int(input()))
for _ in range(10):
    b.append(int(input()))
a.sort()
b.sort()
print(a[-1]+a[-2]+a[-3], end=' ')
print(b[-1]+b[-2]+b[-3])
