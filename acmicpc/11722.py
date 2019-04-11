input()
s = 0
d = [1]*1001
n = input().split(' ')
n = [int(i) for i in n]
for i in range(len(n)):
    for j in range(0, i):
        if n[j] > n[i]:
            d[i] = max(d[i], d[j] + 1)
    s = max(s, d[i])
print(s)
