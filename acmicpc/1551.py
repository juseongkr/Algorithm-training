n, k = map(int, input().split())
l = [*map(int, input().split(','))]
for _ in range(k):
    t = []
    for i in range(len(l)-1):
        t.append(l[i+1]-l[i])
    l = t
for i in range(len(l)):
    print(l[i], end='')
    if i != len(l)-1:
        print(',', end='')
