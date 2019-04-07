n, s = input().split(' ')
l = input().split(' ')
cnt = 0

def dfs(p, v):
    global cnt
    if v + int(l[p]) == int(s):
        cnt += 1
    if p + 1 == int(n):
        return;
    dfs(p + 1, v)
    dfs(p + 1, v + int(l[p]))

dfs(0, 0)
print(cnt)
