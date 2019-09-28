n = int(input())
dp = [0] * 1000
dp[1] = 1
for i in range(2, n):
    dp[i] = dp[i-1] + 2 * dp[i-2]
print(dp[n-1])
