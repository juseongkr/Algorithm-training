l = [0]*101
n = input()
r = 0
t = [*map(int, input().split())]
for i in range(len(t)):
    if l[t[i]] == 1:
        r += 1
    else:
        l[t[i]] = 1
print(r)
