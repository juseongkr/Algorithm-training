for _ in range(int(input())):
    x, y = 0, 0
    for _ in range(int(input())):
        a, b = input().split()
        if a == b:
            continue
        if a == 'R':
            if b == 'P':
                y += 1
            else:
                x += 1
        if a == 'P':
            if b == 'S':
                y += 1
            else:
                x += 1
        if a == 'S':
            if b == 'R':
                y += 1
            else:
                x += 1
    if x == y:
            print("TIE")
    elif x > y:
        print("Player 1")
    else:
        print("Player 2")
