a, b, c = map(int, input().split())
if (a == b and a != c) or (a ==c and a != b) or (b == c and b != a):
    print("Yes")
else:
    print("No")
