class Solution {
public:
	vector<vector<int>> dp;

	int solve(int cur, bool flag, vector<int> &nums) {
		if (cur >= nums.size())
			return 0;
		if (flag && cur == nums.size()-1)
			return 0;

		if (~dp[cur][flag])
			return dp[cur][flag];

		dp[cur][flag] = max(solve(cur+1, flag, nums), solve(cur+2, cur == 0 ? 1 : flag, nums) + nums[cur]);

		return dp[cur][flag];
	}

	int rob(vector<int>& nums) {
		dp.resize(nums.size()+1, vector<int>(2, -1));
		return solve(0, 0, nums);
	}
};
