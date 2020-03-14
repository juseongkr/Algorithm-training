class Solution {
public:
	vector<vector<int>> ans;
	vector<int> vec;

	vector<vector<int>> combinationSum3(int k, int n) {
		solve(0, k, n);
		return ans;
	}

	void solve(int sum, int k, int n) {
		if (vec.size() == k && sum == n) {
			ans.push_back(vec);
			return;
		}

		for (int i=1; i<=9; ++i) {
			if (vec.size() == 0 || vec.size() && vec.back() < i && sum + i <= n) {
				vec.push_back(i);
				solve(sum + i, k, n);
				vec.pop_back();
			}
		}
	}
};
