class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
		int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

		if (left > right-1)
			return {-1, -1};

		return {left, right-1};
	}
};
