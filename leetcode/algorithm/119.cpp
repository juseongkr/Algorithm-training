class solution {
public:
	vector<int> getrow(int rowindex) {
		vector<vector<int>> dp(rowindex+1);

		for (int i=0; i<=rowindex; ++i) {
			dp[i].resize(i+1);
			for (int j=0; j<=i; ++j) {
				if (j == 0 || i == j)
					dp[i][j] = 1;
				else
					dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
			}
		}

		vector<int> ans;
		for (int i=0; i<rowindex+1; ++i)
			ans.push_back(dp[rowindex][i]);

		return ans;
	}
};
