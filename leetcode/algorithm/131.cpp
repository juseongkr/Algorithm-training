class Solution {
public:
	vector<string> vec;
	set<vector<string>> ans;

	bool check(const string a) {
		int n = a.length();
		for (int i=0; i<n/2; ++i)
			if (a[i] != a[n-i-1])
				return false;
		return true;
	}

	void solve(int cur, string s) {
		if (cur == s.length()) {
			ans.insert(vec);
			return;
		}

		for (int i=cur; i<s.length(); ++i) {
			string p = s.substr(cur, i-cur+1);
			if (check(p)) {
				vec.push_back(p);
				solve(i+1, s);
				vec.pop_back();
			}
		}
	}

	vector<vector<string>> partition(string s) {
		solve(0, s);
		vector<vector<string>> ret(ans.begin(), ans.end());

		return ret;
	}
};
