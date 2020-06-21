s = input()
ans = ""
if '::' in s:
    p = s.split(':')
    cnt = 8 - len(p) + p.count('')
    if s[:2] == '::':
        s = s.replace('::', '0:' * cnt)
    else:
        s = s.replace('::', ':' + '0:' * cnt)
if s[-1] == ':':
    s = s[:-1]
s = s.split(':')
for i in s:
    ans += ('0' * (4-len(i))) + i + ':'
print(ans[:-1])
