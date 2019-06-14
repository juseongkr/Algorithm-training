def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)
n = input()
l = [*map(int, input().split())]
for i in range(1, len(l)):
    if l[i] > l[0]:
        t = gcd(l[0], l[i])
    else:
        t = gcd(l[i], l[0])
    print("{}/{}".format(l[0]//t, l[i]//t))
