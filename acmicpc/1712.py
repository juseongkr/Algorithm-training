a, b, c = map(int, input().split())
if b < c:
    print(a//(c-b)+1)
else:
    print(-1)
