class Solution {
public:
	string s;
	vector<int> dp;

	int solve(int cur) {
		if (cur >= s.length())
			return 1;

		if (s[cur] == '0')
			return 0;

		if (~dp[cur])
			return dp[cur];

		dp[cur] = solve(cur+1);
		if (cur+1 < s.length() && (s[cur]-'0') * 10 + s[cur+1]-'0' <= 26)
			dp[cur] += solve(cur+2);

		return dp[cur];
	}

	int numDecodings(string s) {
		dp.resize(s.length()+1, -1);
		this->s = s;

		return solve(0);
	}
};
