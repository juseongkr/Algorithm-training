while True:
    a, b, c = map(int, input().split())
    if a == 0 and b == 0 and c == 0:
        break
    if b*b + c*c == a*a or b*b + a*a == c*c or a*a + c*c == b*b:
        print("right")
    else:
        print("wrong")
