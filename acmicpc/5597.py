l = [0]*31
l[0] = 1
for _ in range(28):
    l[int(input())] = 1
for i in range(len(l)):
    if l[i] == 0:
        print(i)
