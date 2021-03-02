fibo = {}
x, y = 0, 1
for i in range(2, 100001):
    z = str(x + y)[-10:]
    x = y
    y = int(z)
    fibo[z] = i

for _ in range(int(input())):
    print(fibo[input()[-10:]])
