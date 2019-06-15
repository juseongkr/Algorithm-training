for _ in range(int(input())):
    s = 0
    for _ in range(int(input())):
        a, b, c = map(int, input().split())
        if a > 0 or b > 0 or c > 0:
            s += max(a, b, c)
    print(s)
