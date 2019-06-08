for _ in range(int(input())):
    s = set()
    n = input().split()
    while True:
        m = input().split()
        if m[-1] == "say?":
            break
        s.add(m[-1])
    for i in n:
        if i not in s:
            print(i, end=' ')
    print()
