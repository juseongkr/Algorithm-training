n = input()
a, k, r = 0, 0, 0
for i in range(0, len(n)):
    if n[i] != '*':
        if i % 2 == 0:
            a += int(n[i])
        else:
            a += int(n[i]) * 3
    else:
        k = i
if k % 2 == 0:
    while a % 10 != 0:
        a += 1
        r += 1
else:
    while a % 10 != 0:
        a += 3
        r += 1
print(r)
