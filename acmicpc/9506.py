while True:
    n = int(input())
    if n == -1:
        break
    k, s, l = 1, 0, []
    while k != n:
        if n % k == 0:
            l.append(k)
            s += k
        k += 1
    if s == n:
        print(str(n) + ' = ', end='')
        for i in range(len(l)):
            print(l[i], end='')
            if i != len(l)-1:
                print(' + ', end='')
        print()
    else:
        print(str(n) + ' is NOT perfect.')
