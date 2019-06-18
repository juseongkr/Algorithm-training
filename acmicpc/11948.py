l = []
for i in range(6):
    l.append(int(input()))
r = l[0] + l[1] + l[2] + l[3]
r -= min(l[0], l[1], l[2], l[3])
r += max(l[4], l[5])
print(r)
