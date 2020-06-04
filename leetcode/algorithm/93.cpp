class Solution {
public:
	string str;
	vector<string> ans;

	void solve(int cur, int cnt, string s) {
		if (cnt < 0 || cur == str.length()) {
			if (cnt == 0)
				ans.push_back(s.substr(1));
			return;
		}

		for (int i=0; i<3 && cur+i<str.length(); ++i) {
			string next = str.substr(cur, i+1);
			if (stoi(next) > 255)
				break;
			solve(cur+i+1, cnt-1, s + "." + next);
			if (str[cur] == '0')
				break;
		}
	}

	vector<string> restoreIpAddresses(string s) {
		str = s;
		solve(0, 4, "");
		return ans;
	}
};
