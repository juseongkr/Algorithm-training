for i in range(int(input())):
    s = input()
    if s[-1] in 'y':
        print("Case #{}: {} is ruled by nobody.".format(i+1, s))
    elif s[-1] in ['a', 'e', 'i', 'o', 'u']:
        print("Case #{}: {} is ruled by a queen.".format(i+1, s))
    else:
        print("Case #{}: {} is ruled by a king.".format(i+1, s))
