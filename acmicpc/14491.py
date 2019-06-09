n, r, c = int(input()), 0, 0
while n > 0:
    r += n % 9 * pow(10, c)
    c += 1
    n //= 9
print(r)
