a, b, c = map(int, input().split())
print(max(abs(a-b), abs(b-c))-1)
