l = []
for i in range(9):
    l.append([int(input()), i+1])
l.sort()
print(l[-1][0])
print(l[-1][1])
