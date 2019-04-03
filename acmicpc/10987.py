l = ['a', 'e', 'i', 'o', 'u']
c = 0
for i in input():
    for j in l:
        if i == j:
            c += 1
print(c)
