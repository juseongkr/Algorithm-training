n, k = map(int, input().split())
l = [*map(int, input().split())]
t = []
for i in range(1, len(l)):
    t.append(l[i]-l[i-1])
t.sort()
print(sum(t[:n-k]))
