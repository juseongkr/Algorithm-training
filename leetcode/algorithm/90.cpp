class Solution {
public:
	set<vector<int>> ret;
	vector<int> vec;

	void solve(int idx, vector<int> &nums) {
		if (idx == nums.size()) {
			sort(vec.begin(), vec.end());
			ret.insert(vec);
			return;
		}

		vec.push_back(nums[idx]);
		solve(idx+1, nums);
		vec.pop_back();
		solve(idx+1, nums);
	}

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		solve(0, nums);

		vector<vector<int>> ans;
		for (const auto v : ret)
			ans.push_back(v);

		return ans;
	}
};
