l = [*map(int, input().split())]
l.sort()
print(abs((l[0]+l[3])-(l[1]+l[2])))
