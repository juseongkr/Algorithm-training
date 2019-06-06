import math
n, w, h = map(int, input().split())
for _ in range(n):
    t = int(input())
    if t <= w or t <= h or t <= math.sqrt(w*w + h*h):
        print("DA")
    else:
        print("NE")
