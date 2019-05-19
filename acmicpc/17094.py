n = input()
s = input()
a, b = 0, 0
for i in s:
    if i == 'e':
        a += 1
    else:
        b += 1

if a > b:
    print("e")
elif a < b:
    print("2")
else:
    print("yee")
