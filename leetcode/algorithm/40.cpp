class Solution {
public:
	set<vector<int>> ret;
	vector<bool> visit;
	vector<int> vec;

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		visit.resize(candidates.size(), 0);
		sort(candidates.begin(), candidates.end());
		solve(0, 0, candidates, target);

		return {ret.begin(), ret.end()};
	}

	void solve(int sum, int cur, vector<int> &candidates, int target) {
		if (sum == target) {
			ret.insert(vec);
			return;
		}

		for (int i=cur; i<candidates.size(); ++i) {
			if (sum + candidates[i] <= target && !visit[i]) {
				visit[i] = 1;
				vec.push_back(candidates[i]);
				solve(sum + candidates[i], i+1, candidates, target);
				vec.pop_back();
				visit[i] = 0;
			}
		}
	}
};
