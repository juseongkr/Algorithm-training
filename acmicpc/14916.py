n = int(input())
cnt = 0
while n > 0:
    if n%5 == 0:
        print(cnt + n//5)
        exit(0)
    else:
        n -= 2
        cnt += 1
if n == 0:
    print(cnt)
else:
    print(-1)
