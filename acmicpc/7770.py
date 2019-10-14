n, b, h = input(), 0, 0
while b <= int(n):
    b += 2*(h**2) + 2*h + 1
    h += 1
print(h-1)
