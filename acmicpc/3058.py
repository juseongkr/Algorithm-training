for _ in range(int(input())):
    l = [*map(int, input().split())]
    s, m = 0, []
    for i in l:
        if i % 2 == 0:
            s += i
            m.append(i)
    m.sort()
    print(s, end=' ')
    print(m[0])
