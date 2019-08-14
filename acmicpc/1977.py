from math import *
a = ceil(sqrt(int(input())))
b = floor(sqrt(int(input())))
r = 0
for i in range(a, b+1):
    r += i*i
if r != 0:
    print("{}\n{}".format(r, a*a))
else:
    print(-1)
