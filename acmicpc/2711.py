for _ in range(int(input())):
    k, s = input().split()
    for i in range(len(s)):
        if i != int(k)-1:
            print(s[i], end='')
    print()
