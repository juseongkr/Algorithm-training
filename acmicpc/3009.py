x1, y1 = input().split()
x2, y2 = input().split()
x3, y3 = input().split()
if x1 == x2 and y1 == y3:
    print(x3+' '+y2)
elif x1 == x3 and y1 == x2:
    print(x2+' '+y3)
elif x2 == x1 and y2 == y3:
    print(x3+' '+y1)
elif x2 == x3 and y2 == y1:
    print(x1+' '+y3)
elif x3 == x1 and y3 == y2:
    print(x2+' '+y1)
elif x3 == x2 and y3 == y1:
    print(x1+' '+y2)
