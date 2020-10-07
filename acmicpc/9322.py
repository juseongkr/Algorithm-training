for _ in range(int(input())):
    n = int(input())
    fir, sec = {}, {}
    for i, k in enumerate(input().split()):
        fir[k] = i

    for i, k in enumerate(input().split()):
        sec[fir[k]] = i

    pw = input().split()
    for i in range(n):
        print(pw[sec[i]], end=' ')
    print()
