for _ in range(int(input())):
    a, b, c, r = map(int, input().split())
    if a > b:
        a, b = b, a
    l = b-a
    r = max(0, min(b, c+r) - max(a, c-r))
    print(l-r)
