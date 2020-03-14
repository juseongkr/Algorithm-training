class Solution {
public:
	string str;
	vector<vector<int>> dp;

	int solve(int a, int b) {
		if (a == b)
			return 1;
		if (a > b)
			return 0;

		if (dp[a][b])
			return dp[a][b];

		if (str[a] == str[b])
			return dp[a][b] = solve(a+1, b-1) + 2;

		dp[a][b] = max(solve(a, b-1), solve(a+1, b));

		return dp[a][b];
	}

	int longestPalindromeSubseq(string s) {
		str = s;
		dp.resize(s.length()+1);
		for (int i=0; i<dp.size(); ++i)
			dp[i].resize(s.length()+1, 0);

		return solve(0, s.length()-1);
	}
};
