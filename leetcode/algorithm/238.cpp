class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> dp(nums.size(), 1);

		for (int i=1; i<nums.size(); ++i)
			dp[i] = dp[i-1] * nums[i-1];

		int val = 1;
		for (int i=nums.size()-1; i>=0; i--) {
			dp[i] *= val;
			val *= nums[i];
		}

		return dp;
	}
};
