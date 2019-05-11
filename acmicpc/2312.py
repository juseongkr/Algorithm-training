t = int(input())
for k in range(t):
    n = int(input())
    for i in range(2, n+1):
        c = 0
        while n % i == 0:
            n = n // i
            c += 1
        if c:
            print(str(i) + " " + str(c))
