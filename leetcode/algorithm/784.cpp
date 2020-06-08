class Solution {
public:
	vector<string> ans;

	void solve(int cur, string s) {
		if (cur == s.length()) {
			ans.push_back(s);
			return;
		}

		solve(cur+1, s);
		if (isalpha(s[cur])) {
			s[cur] ^= 32;
			solve(cur+1, s);
			s[cur] ^= 32;
		}
	}

	vector<string> letterCasePermutation(string S) {
		solve(0, S);
		return ans;
	}
};
