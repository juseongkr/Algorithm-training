import math
a, b = map(int, input().split())
print(math.factorial(a)//(math.factorial(b)*math.factorial(a-b)))
