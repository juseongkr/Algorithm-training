n = input()
l = [*map(int, input().split())]
k, r = 1, 0
for i in l:
    if i == 0:
        k = 1
    else:
        r += k
        k += 1
print(r)
