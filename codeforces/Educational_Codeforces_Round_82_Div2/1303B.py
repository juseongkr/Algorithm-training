for _ in range(int(input())):
    n, g, b = map(int, input().split())
    half = (n+1) // 2
    ans = half // g * (g + b) + half % g
    if half % g == 0:
        ans -= b
    print(max(n, ans))
