n, c = map(int, input().split())
a = []
for _ in range(n):
    a.append(int(input()))
a.sort()

def check(t):
    k, p = 1, a[0]
    for i in range(1, n):
        if a[i] - p >= t:
            p = a[i]
            k += 1
    if k >= c:
        return True
    return False

ans, l, r = 0, 1, a[-1] - a[0]
while l <= r:
    m = (l+r)//2;
    if check(m):
        ans = max(ans, m)
        l = m + 1
    else:
        r = m - 1
print(ans)
