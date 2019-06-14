a, b = map(int, input().split())
if (a+b)%2 == 0:
    x = (a+b)//2
    y = a-x
    if x < y:
        x, y = y, x
    if x < 0 or y < 0:
        print(-1)
    else:
        print(str(x)+' '+str(y))
else:
    print(-1)
