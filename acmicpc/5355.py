for _ in range(int(input())):
    l = input().split()
    r = float(l[0])
    for i in l[1:]:
        if i == '@':
            r *= 3
        elif i == '%':
            r += 5
        elif i == '#':
            r -= 7
    print("{:.2f}".format(r))
