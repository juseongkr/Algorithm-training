s, r = input(), '~'
for i in range(0, len(s)-2):
    for j in range(i+1, len(s)-1):
        r = min(r, s[i::-1]+s[j:i:-1]+s[:j:-1])
print(r)
