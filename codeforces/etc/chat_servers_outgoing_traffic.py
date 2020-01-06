n = 0
try:
    i = 0
    while True:
        m = input()
        if m[0] == '+':
            n += 1
        elif m[0] == '-':
            n -= 1
        else:
            i += (len(m.split(':')[1]) * n)
except:
    pass

print(i)
