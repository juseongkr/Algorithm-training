p = []
for _ in range(int(input())):
    p.append(input())

for _ in range(int(input())):
    s = input()
    ans = "NO"
    for i in p:
        if s.find(i) != -1:
            ans = "YES"
            break
    print(ans)
