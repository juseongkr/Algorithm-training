class Solution {
public:
	vector<vector<int>> ret;
	vector<int> vec;

	void solve(int idx, vector<int> &nums) {
		if (idx == nums.size()) {
			ret.push_back(vec);
			return;
		}

		vec.push_back(nums[idx]);
		solve(idx+1, nums);
		vec.pop_back();
		solve(idx+1, nums);
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		solve(0, nums);
		return ret;
	}
};
