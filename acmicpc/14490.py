def gcd(a, b):
    if a%b == 0:
        return b
    return gcd(b, a%b)
a, b = map(int, input().split(':'))
print(a//gcd(a, b), end=':')
print(b//gcd(a, b))
