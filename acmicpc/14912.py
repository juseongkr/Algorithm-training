a, b = map(int, input().split())
r = 0
for i in range(a):
    r += str(i+1).count(str(b))
print(r)
