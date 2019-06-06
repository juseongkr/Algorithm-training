n = int(input())
a, b = input().split('*')
for _ in range(n):
    t = input()
    if len(t) < len(a)+len(b)-1:
        print("NE")
        continue
    if a == t[:len(a)] and b == t[len(t)-len(b):]:
        print("DA")
    else:
        print("NE")
