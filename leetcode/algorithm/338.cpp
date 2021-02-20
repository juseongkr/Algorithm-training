class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> dp(num+1, 0);

		if (num >= 1)
			dp[1] = 1;
		if (num >= 2)
			dp[2] = 1;   

		for (int i=3; i<=num; ++i) {
			if (i & 1)
				dp[i] = dp[i-1] + 1;
			else
				dp[i] = dp[i/2];
		}

		return dp;
	}
};
