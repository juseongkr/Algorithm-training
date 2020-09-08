class Solution {
public:
	vector<vector<int>> dp;
	string s, p;

	bool solve(int i, int j) {
		if (i == 0 && j == 0)
			return 1;

		if (i < 0 || j <= 0)
			return 0;

		if (~dp[i][j])
			return dp[i][j];

		dp[i][j] = 0;
		if (p[j-1] == '*') {
			if (i > 0 && j > 1 && (s[i-1] == p[j-2] || p[j-2] == '.'))
				dp[i][j] = (solve(i, j-2) || solve(i-1, j));
			else
				dp[i][j] = solve(i, j-2);
		} else if (i > 0 && j > 0 && (s[i-1] == p[j-1] || p[j-1] == '.')) {
			dp[i][j] = solve(i-1, j-1);
		}

		return dp[i][j];
	}

	bool isMatch(string s, string p) {
		this->s = s;
		this->p = p;
		dp.resize(s.length()+1, vector<int>(p.length()+1, -1));

		return solve(s.length(), p.length());
	}
};
