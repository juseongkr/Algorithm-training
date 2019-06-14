for _ in range(int(input())):
    s = input()
    g, b = s.lower().count('g'), s.lower().count('b')
    if g == b:
        print(s + ' is NEUTRAL')
    elif g < b:
        print(s + ' is A BADDY')
    else:
        print(s + ' is GOOD')
