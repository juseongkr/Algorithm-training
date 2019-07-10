while True:
    n = int(input())
    if n == 0:
        break
    ans = 0
    for i in range(n):
        flag = True
        s = input()
        for j in range(len(s)):
            if s[j] == ' ' and ans <= j:
                flag = False
                ans = j
                break
        if flag and ans < len(s):
            ans = len(s)
    print(ans+1)
