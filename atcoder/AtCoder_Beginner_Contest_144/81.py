l = [0]*101
for i in range(1, 10):
    for j in range(1, 10):
        l[i*j] = 1
n = int(input())
if l[n] == 1:
    print("Yes")
else:
    print("No")
