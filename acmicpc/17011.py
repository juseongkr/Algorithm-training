for _ in range(int(input())):
    s = input()
    p, c = s[0], 0
    for i in s:
        if p == i:
            c += 1
        else:
            print(str(c)+' '+p, end=' ')
            p = i
            c = 1
    print(str(c)+' '+p)
