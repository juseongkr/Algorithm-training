for _ in range(int(input())):
    s = input()
    _ = input()
    n = input()
    n = n[1:-1].split(',')
    p, e = 1, False
    for i in s:
        if i == 'R':
            p *= -1
        elif i == 'D':
            if len(n) == 0 or n[0] == '':
                e = True
            else:
                if p == 1:
                    del n[0]
                else:
                    del n[-1]
    if e:
        print('error')
    else:
        r = ''
        if p == -1:
            n.reverse()
        for i in range(len(n)):
            r += n[i]
            if i < len(n)-1:
                r += ','
        print('[' + r + ']')
