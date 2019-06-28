l = map(int, input().split())
m = 5000
for i in l:
    if i == 1:
        m -= 500
    elif i == 2:
        m -= 800
    else:
        m -= 1000
print(m)
