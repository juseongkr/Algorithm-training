n = int(input())
l = [*map(int, input().split())]
l.sort()
for i in l:
    print(i, end=' ')
