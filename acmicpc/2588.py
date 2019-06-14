a = int(input())
b = int(input())
r = a * b
while True:
    if b == 0:
        break
    print(a * (b % 10))
    b //= 10
print(r)
