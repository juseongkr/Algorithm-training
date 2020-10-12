from math import comb
n, k = map(int, input().split())
print(comb(n-1, k-1))
