l = []
n = input()
for i in range(len(n)):
    l.append(n[i:])
l.sort()
for i in l:
    print(i)
