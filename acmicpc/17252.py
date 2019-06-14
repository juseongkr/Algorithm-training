n = int(input())
flag = True
if n == 0:
    flag = False
while True:
    if n == 0:
        break
    if n % 3 == 2:
        flag = False
        break
    n //= 3
if flag:
    print("YES")
else:
    print("NO")
