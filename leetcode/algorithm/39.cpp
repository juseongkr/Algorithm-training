class Solution {
public:
	vector<vector<int>> ans;
	vector<int> vec;

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		solve(0, 0, candidates, target);

		return ans;
	}

	void solve(int sum, int cur, vector<int> &candidates, int target) {
		if (sum == target) {
			ans.push_back(vec);
			return;
		}

		for (int i=cur; i<candidates.size(); ++i) {
			if (sum + candidates[i] <= target) {
				vec.push_back(candidates[i]);
				solve(sum + candidates[i], i, candidates, target);
				vec.pop_back();
			}
		}
	}
};
