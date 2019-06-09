s = input()
i, t = 0, True
while i != len(s):
    if s[i:i+2] in ['pi', 'ka']:
        i += 2
    elif s[i:i+3] == 'chu':
        i += 3
    else:
        t = False
        break
if t:
    print("YES")
else:
    print("NO")
