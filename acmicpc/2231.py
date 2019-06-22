n, flag = int(input()), True
for i in range(1000001):
    k, ans = i, i
    while k:
        ans += k % 10
        k //= 10
    if ans == n:
        flag = False
        print(i)
        break
if flag:
    print(0)
