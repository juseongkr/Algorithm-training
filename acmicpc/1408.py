a = [*map(int, input().split(':'))]
b = [*map(int, input().split(':'))]
s = a[0]*3600 + a[1]*60 + a[2]
e = b[0]*3600 + b[1]*60 + b[2]
if s > e:
    e += 3600*24
r = e - s
print("{0:02d}".format(r//3600), end=':')
r %= 3600
print("{0:02d}".format(r//60), end=':')
r %= 60
print("{0:02d}".format(r))
