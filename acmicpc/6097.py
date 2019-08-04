a, b = input().split()
s = str(int(a)**int(b))
for i in range(len(s)):
    if i % 70 == 0 and i != 0:
        print()
    print(s[i], end='')
