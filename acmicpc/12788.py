n = int(input())
m, k = map(int, input().split())
a = [*map(int, input().split())]
a.sort()
s = 0
for i in range(0, len(a)):
    s += a[len(a)-1-i]
    if s >= m*k:
        print(i+1)
        exit()
print("STRESS")
