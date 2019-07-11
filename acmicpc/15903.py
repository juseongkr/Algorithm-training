n, m = map(int, input().split())
l = [*map(int, input().split())]
for _ in range(m):
    l.sort()
    l[0], l[1] = l[0]+l[1], l[0]+l[1]
print(sum(l))
