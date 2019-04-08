input()
l = input().split(' ')
l = [int(i) for i in l]
l.sort()
print(l[0], l[-1])
