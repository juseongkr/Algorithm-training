a = input().split()
b = input().split()
s = 0
for i, j in zip(a, b):
    if int(i) < int(j):
        s += int(j)-int(i)
print(s)
