for _ in range(int(input())):
    a, b, c, d, e, f, g, h = map(int, input().split())
    a += e
    b += f
    c += g
    d += h
    if a < 1:
        a = 1
    if b < 1:
        b = 1
    if c < 0:
        c = 0
    print(a + (5 * b) + (2 * c) + (2 * d))
