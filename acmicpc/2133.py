dp = [-1]*31
def dfs(n):
    if n%2 != 0:
        return 0
    elif n == 0:
        return 1
    elif n == 2:
        return 3
    if dp[n] != -1:
        return dp[n]
    dp[n] = dfs(n-2) * 3
    for i in range(n-3):
        dp[n] += dfs(i) * 2
    return dp[n]

print(dfs(int(input())))
