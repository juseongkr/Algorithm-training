dp = [0]*21
dp[1] = 1
n = int(input())
for i in range(2, len(dp)):
    dp[i] = dp[i-1] + dp[i-2]
print(dp[n])
