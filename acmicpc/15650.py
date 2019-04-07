n, m = input().split(' ')
v = [0]*10
l = []

def dfs():
    if len(l) == int(m):
        for i in l:
            print(i, end=' ')
        print()
        return;

    for i in range(1, int(n)+1):
        if not v[i]:
            v[i] = 1
            if len(l) == 0:
                l.append(i)
                dfs()
                l.pop()
            elif l[-1] < i:
                l.append(i)
                dfs()
                l.pop()
            v[i] = 0
dfs()
