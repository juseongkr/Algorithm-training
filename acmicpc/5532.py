from math import *
n = []
for _ in range(5):
    n.append(int(input()))
print(n[0]-max(ceil(float(n[1])/n[3]), ceil(float(n[2])/n[4])))
