class Solution {
public:
	vector<int> dp;

	int solve(int sum, vector<int> &nums, int target) {
		if (sum == target)
			return 1;

		if (~dp[sum])
			return dp[sum];

		dp[sum] = 0;
		for (int i=0; i<nums.size(); ++i)
			if (sum + nums[i] <= target)
				dp[sum] += solve(sum + nums[i], nums, target);

		return dp[sum];
	}

	int combinationSum4(vector<int>& nums, int target) {
		dp.resize(target+1, -1);
		return solve(0, nums, target);
	}
};
