for _ in range(int(input())):
    s = input()
    if s[0].islower():
        print(s[0].upper(), end='')
        print(s[1:])
    else:
        print(s)
