class Solution {
public:
	vector<vector<int>> ans;
	vector<int> vec, temp;

	vector<vector<int>> combine(int n, int k) {
		for (int i=1; i<=n; ++i)
			vec.push_back(i);

		solve(0, k);
		return ans;
	}

	void solve(int cur, int k) {
		if (k == 0) {
			ans.push_back(temp);
			return;
		}

		for (int i=0; i<vec.size(); ++i) {
			if (temp.size() == 0 || (temp.size() && temp.back() < vec[i])) {
				temp.push_back(vec[i]);
				solve(i, k-1);
				temp.pop_back();
			}
		}
	}
};
