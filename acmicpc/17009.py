a, b = 0, 0
for i in range(3, 0, -1):
    a += i * int(input())
for i in range(3, 0, -1):
    b += i * int(input())
if a > b:
    print('A')
elif a < b:
    print('B')
else:
    print('T')
