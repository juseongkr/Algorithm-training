input()
l = [*map(int, input().split())]
l.sort()
print(max(l[0]*l[1], l[0]*l[1]*l[-1], l[-1]*l[-2]*l[-3], l[-1]*l[-2]))
