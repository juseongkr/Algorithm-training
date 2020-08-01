class Solution {
public:
	vector<string> nums = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	vector<string> ans;

	void solve(int cur, string s, string p) {
		if (cur == p.length()) {
			ans.push_back(s);
			return;
		}

		int idx = p[cur]-'0';
		for (int i=0; i<nums[idx].size(); ++i) {
			s += nums[idx][i];
			solve(cur+1, s, p);
			s.pop_back();
		}
	}

	vector<string> letterCombinations(string digits) {
		if (digits.length())
			solve(0, "", digits);
		return ans;
	}
};
