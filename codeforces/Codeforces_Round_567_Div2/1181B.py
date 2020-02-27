n = int(input())
s = input()
mid = n//2;
ans = int(s)
for i in range(mid, 0, -1):
    if s[i] != '0':
        val = int(s[:i]) + int(s[i:])
        ans = min(ans, val)
        break
for i in range(mid+1, n):
    if s[i] != '0':
        val = int(s[:i]) + int(s[i:])
        ans = min(ans, val)
        break
print(ans)
