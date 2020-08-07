class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		set<vector<int>> vec;
		sort(nums.begin(), nums.end());
		for (int i=0; i<nums.size(); ++i) {
			for (int j=i+1; j<nums.size(); ++j) {
				int l = j+1, r = nums.size()-1;
				while (l < r) {
					int sum = nums[i] + nums[j] + nums[l] + nums[r];
					if (sum == target) {
						vec.insert({nums[i], nums[j], nums[l], nums[r]});
						l++;
						r--;
					} else if (sum < target) {
						l++;
					} else {
						r--;
					}
				}
			}
		}

		vector<vector<int>> ans(vec.begin(), vec.end());
		return ans;
	}
};
