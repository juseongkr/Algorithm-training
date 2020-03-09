class Solution {
public:
	int total;
	vector<string> ret;

	void solve(int a, int b, string s) {
		if (a+b == total*2) {
			ret.push_back(s);
			return;
		}
		if (a < total)
			solve(a+1, b, s+"(");
		if (a > b)
			solve(a, b+1, s+")");
	}

	vector<string> generateParenthesis(int n) {
		total = n;
		solve(0, 0, "");
		return ret;
	}
};
