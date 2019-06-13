b = [0, 1, 0, 0]
f = True
for _ in range(int(input())):
    x, y = map(int, input().split())
    b[x], b[y] = b[y], b[x]
for i in range(1, 4):
    if b[i] == 1:
        f = False
        print(i)
if f:
    print(-1)
