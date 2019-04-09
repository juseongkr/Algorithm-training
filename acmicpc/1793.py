import sys
dp = [0]*251
def solve(i):
    if i == 0:
        return 1
    if i == 1:
        return 1
    elif i == 2:
        return 3
    if dp[i]:
        return dp[i]
    dp[i] = solve(i-2) * 2 + solve(i-1)
    return dp[i]

for i in sys.stdin:
    n = int(i.strip())
    print(solve(n))
