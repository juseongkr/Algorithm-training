n = int(input())
s = input()
a, b = 0, 0
for i in range(0, n):
    if s[i] == 'O':
        a += i+1 + b
        b += 1
    else:
        b = 0
print(a)
