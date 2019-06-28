l = int(input())
r = int(input())
i, t = 2, 0
while True:
    l = int((r/100) * l)
    if l <= 5:
        break
    t += l * i
    i *= 2
print(t)
