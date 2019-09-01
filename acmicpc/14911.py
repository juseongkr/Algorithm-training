l = [*map(int, input().split())]
k = int(input())
m, cnt = [], 0
l.sort()
for i in range(len(l)):
    for j in range(i+1, len(l)):
        if l[i] + l[j] == k and (l[i], l[j]) not in m:
            print("{} {}".format(l[i], l[j]))
            m.append((l[i], l[j]))
            cnt += 1
print(cnt)
