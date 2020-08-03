class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int min_val = 1e9+7, ans = 1e9+7;
		sort(nums.begin(), nums.end());
		for (int m=0; m<nums.size(); ++m) {
			int l = 0, r = nums.size()-1;
			while (l < m && m < r) {
				int sum = nums[l] + nums[m] + nums[r];
				if (abs(target - sum) < min_val) {
					min_val = abs(target - sum);
					ans = sum;
				} else if (target == sum) {
					return sum;
				}

				if (sum < target) {
					l++;
				} else {
					r--;
				}
			}
		}
		return ans;
	}
};
