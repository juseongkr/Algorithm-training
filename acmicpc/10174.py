for i in range(int(input())):
    s = input().lower()
    if s == s[::-1]:
        print("Yes")
    else:
        print("No")
