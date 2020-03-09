class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret;

		int n = nums.size();
		sort(nums.begin(), nums.end());
		for (int l=0; l<n; ++l) {
			if (l == 0 || nums[l] > nums[l-1]) {
				int m = l+1;
				int r = n-1;
				while (m < r) {
					int sum = nums[l] + nums[m] + nums[r];
					if (sum == 0) {
						ret.push_back({nums[l], nums[m], nums[r]});
						m++;
						r--;
						while (m < r && nums[m] == nums[m-1])
							m++;
						while (m < r && nums[r] == nums[r+1])
							r--;
					} else if (sum < 0) {
						m++;
					} else {
						r--;
					}
				}
			}
		}

		return ret;
	}
};
