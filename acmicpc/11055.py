input()
s = 0
d = [0]*1001
n = input().split(' ')
n = [int(i) for i in n]
for i in range(len(n)):
    d[i] = n[i]
    for j in range(0, i):
        if n[j] < n[i]:
            d[i] = max(d[i], d[j] + n[i])
    s = max(s, d[i])
print(s)
