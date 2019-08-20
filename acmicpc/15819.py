a, b = map(int, input().split())
l = []
for _ in range(a):
    l.append(input())
l.sort()
print(l[b-1])
