for _ in range(int(input())):
    n = input()
    r = n[::-1]
    s = str(int(n)+int(r))
    if s == s[::-1]:
        print("YES")
    else:
        print("NO")
