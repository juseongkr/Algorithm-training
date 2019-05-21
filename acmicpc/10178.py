for i in range(int(input())):
    a, b = input().split()
    print("You get {} piece(s) and your dad gets {} piece(s).".format(int(a)//int(b), int(a)%int(b)))
