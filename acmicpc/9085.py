for _ in range(int(input())):
    r, n = 0, input()
    s = [*map(int, input().split())]
    for i in s:
        r += int(i)
    print(r)
