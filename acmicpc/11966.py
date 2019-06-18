n = int(input())
l, flag = [], False
for i in range(32):
    l.append(1 << i)
for i in range(32):
    if l[i] == n:
        flag = True
        break
if flag:
    print(1)
else:
    print(0)
