class Solution {
public:
	int dp[1001][1001];

	int solve(int cur, int copy, int n) {
		if (cur > n || copy > n)
			return 1e9+7;
		if (cur == n)
			return 0;

		if (~dp[cur][copy])
			return dp[cur][copy];

		dp[cur][copy] = solve(cur+copy, copy, n) + 1;
		if (cur != copy)
			dp[cur][copy] = min(dp[cur][copy], solve(cur, cur, n) + 1);

		return dp[cur][copy];
	}

	int minSteps(int n) {
		if (n == 1)
			return 0;
		memset(dp, -1, sizeof(dp));
		return solve(2, 1, n) + 2;
	}
};
