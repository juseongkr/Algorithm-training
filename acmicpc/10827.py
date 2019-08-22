import decimal
decimal.getcontext().prec = 10000
a, b = input().split()
print("{0:f}".format(decimal.Decimal(a)**int(b)))
