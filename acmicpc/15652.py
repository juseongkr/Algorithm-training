n, m = input().split(' ')
l = []

def dfs():
    if len(l) == int(m):
        for i in l:
            print(i, end=' ')
        print()
        return;
    for i in range(1, int(n)+1):
        if len(l) == 0 or l[-1] <= i:
            l.append(i)
            dfs()
            l.pop()
dfs()
