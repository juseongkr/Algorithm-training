_ = input()
x = set([*map(int, input().split())])
y = set([*map(int, input().split())])
print(len(x-y))
for i in sorted(list(x-y)):
    print(i, end=' ')
