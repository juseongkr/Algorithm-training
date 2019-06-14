for _ in range(int(input())):
    s = input().split()
    for i in range(2, len(s)):
        print(s[i], end=' ')
    print(s[0]+' '+s[1])
