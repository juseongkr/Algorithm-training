c, n = 0, input()
l = [*map(int, input().split())]
v = int(input())
for i in l:
    if i == v:
        c += 1
print(c)
