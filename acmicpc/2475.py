n = map(int, input().split())
r = 0
for i in n:
    r += i**2
print(r%10)
