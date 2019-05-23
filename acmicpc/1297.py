from math import *
d, h, w = input().split()
d, h, w = int(d), int(h), int(w)
c = sqrt(h**2 + w**2)
print(int(h*d/c), end=' ')
print(int(w*d/c))
