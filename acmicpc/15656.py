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
        v.append(i)
        dfs()
        v.pop()

dfs()
