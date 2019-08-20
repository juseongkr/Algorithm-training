a = int(input())
b = int(input())
r = 1
if a < 0 and b > 0:
    r = 2
elif a < 0 and b < 0:
    r = 3
elif a > 0 and b < 0:
    r = 4
print(r)
