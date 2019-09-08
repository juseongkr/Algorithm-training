n, k = map(int, input().split())
l = input().split()
for i in range(k):
    n -= (int(l[i])+1)//2
if n > 0:
    print("NO")
else:
    print("YES")
