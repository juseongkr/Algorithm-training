class Solution {
public:
	int total = 0;
	int dp[201][20001];

	int solve(int cur, int sum, vector<int>& nums) {
		if (cur == nums.size())
			return 0;

		if (~dp[cur][sum])
			return dp[cur][sum];

		if (sum - nums[cur] >= 0)
			dp[cur][sum] = max(dp[cur][sum], solve(cur+1, sum-nums[cur], nums) + nums[cur]);
		dp[cur][sum] = max(dp[cur][sum], solve(cur+1, sum, nums));

		return dp[cur][sum];
	}

	bool canPartition(vector<int>& nums) {
		for (const auto i : nums)
			total += i;

		if (total % 2)
			return false;

		total /= 2;
		memset(dp, -1, sizeof(dp));
		return solve(0, total, nums) == total;
	}
};
