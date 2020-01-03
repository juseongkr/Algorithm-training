n, a = int(input()), 0
for _ in range(n-1):
    _, _, k = input().split()
    a ^= int(k)
print(a)
