while True:
    s = input()
    if s == '#':
        break
    c, r = 0, ""
    for i in range(len(s)-1):
        if s[i] == '1':
            c += 1
        r += s[i]
    if s[-1] == 'e':
        if c % 2 == 0:
            r += '0'
        else:
            r += '1'
    else:
        if c % 2 == 0:
            r += '1'
        else:
            r += '0'
    print(r)
