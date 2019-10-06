l = [*map(int, input().split())]
l.sort()
if l[0]+l[3] == l[1]+l[2] or l[3] == l[0]+l[1]+l[2]:
    print("YES")
else:
    print("NO")
