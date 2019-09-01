a, d, k = map(int, input().split())
if (k-a)%d or (k-a)//d < 0:
    print("X")
else:
    print((k-a)//d+1)
