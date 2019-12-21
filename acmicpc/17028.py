n = int(input())-1
l = [*map(int, input().split())]
for i in range(len(l)-2, -1, -1):
    if l[i] < l[i+1]:
        n = i
    else:
        break
print(n)
