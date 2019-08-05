for _ in range(int(input())):
    a, b = map(int, input().split())
    print("{} {}".format(b-(a-b), a-b))
