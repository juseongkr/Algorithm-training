r = 0
for _ in range(int(input())):
    a, b = map(int, input().split())
    r += (b % a)
print(r)
