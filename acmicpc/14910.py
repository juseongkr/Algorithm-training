l = [*map(int, input().split())]
p = l[0]
for i in range(1, len(l)):
    if p > l[i]:
        print("Bad")
        exit(0)
    p = l[i]
print("Good")
