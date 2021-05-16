class Solution {
public:
	const int INF = 1e9+7;
	const int MAX = 1001;

	int jump(vector<int>& nums) {
		int dp[MAX];
		fill(dp+1, dp+MAX, INF);

		int n = nums.size();
		for (int i=0; i<n; ++i)
			for (int j=i+1; j<=min(nums[i] + i, n - 1); ++j)
				dp[j] = min(dp[j], dp[i] + 1);

		return dp[n-1];
	}
};
