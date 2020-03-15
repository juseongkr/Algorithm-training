class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		vector<vector<int>> dp;
		int n = text1.length();
		int m = text2.length();

		dp.resize(n+1);
		for (int i=0; i<=n; ++i)
			dp[i].resize(m+1, 0);

		for (int i=1; i<=n; ++i) {
			for (int j=1; j<=m; ++j) {
				if (text1[i-1] == text2[j-1])
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
		return dp[n][m];
	}
};
