class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<bool> dp(s.length()+1, 0);

		dp[0] = true;
		for (int i=1; i<=s.length(); ++i) {
			for (const auto j : wordDict) {
				int len = j.length();
				int idx = i - len;
				if (idx >= 0 && dp[idx] && s.substr(idx, len) == j) {
					dp[i] = true;
					break;
				}
			}
		}
		return dp[s.length()];
	}
};
