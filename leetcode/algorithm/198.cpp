class Solution {
public:
	int n;
	vector<int> dp;

	int solve(int cur, vector<int> &nums) {
		if (cur < 0)
			return 0;

		if (cur == 0)
			return nums[0];
		else if (cur == 1)
			return max(nums[0], nums[1]);

		if (~dp[cur])
			return dp[cur];

		dp[cur] = max(solve(cur-1, nums), solve(cur-2, nums) + nums[cur]);

		return dp[cur];
	}

	int rob(vector<int>& nums) {
		n = nums.size();
		dp.resize(n+1, -1);

		return solve(n-1, nums);
	}
};
