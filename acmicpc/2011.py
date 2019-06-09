dp, s = [0]*5001, input()
dp[0], MOD = 1, 1000000
if s == '0':
    print(0)
else:
    for i in range(1, len(s)+1):
        if  1 <= int(s[i-1]) <= 9:
            dp[i] = (dp[i] + dp[i-1]) % MOD
        if i == 1:
            continue;
        if 10 <= int(s[i-2:i]) <= 26:
            dp[i] = (dp[i] + dp[i-2]) % MOD
    print(dp[len(s)])
