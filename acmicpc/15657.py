n, m = input().split(' ')
l = input().split(' ')
l = [int(i) for i in l]
l.sort()
v = []

def dfs():
    if len(v) == int(m):
        for i in v:
            print(i, end=' ')
        print()
        return
    for i in l:
        if len(v) == 0:
            v.append(i)
            dfs()
            v.pop()
        elif v[-1] <= i:
            v.append(i)
            dfs()
            v.pop()

dfs()
