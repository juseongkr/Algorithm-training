d = {0:'zero', 1:'one', 2:'two', 3:'three', 4:'four', 5:'five', 6:'six', 7:'seven', 8:'eight', 9:'nine'}
m, l = {}, []
a, b = map(int, input().split())
for i in range(a, b+1):
    if i >= 10:
        k = d[i//10]+d[i%10]
        l.append(k)
        m[k] = i
    else:
        l.append(d[i])
        m[d[i]] = i
l.sort()
t = 0
for i in range(len(l)):
    print(m[l[i]], end=' ')
    t += 1
    if t % 10 == 0:
        print()
