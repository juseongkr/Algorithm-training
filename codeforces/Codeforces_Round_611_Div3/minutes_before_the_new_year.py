for _ in range(int(input())):
    t = 24*60
    h, m = map(int, input().split())
    print(t-(h*60)-m)
