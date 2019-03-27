n = "00" + input()
l = len(n)
for i in range(l%3, l, 3):
    print(int(n[i])*4 + int(n[i+1])*2 + int(n[i+2]), end='')
