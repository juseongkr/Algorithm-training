class Solution {
public:
	int n, m;
	vector<vector<int>> dp;

	int solve(int x, int y, vector<vector<int>> &grid) {
		if (x == n-1 && y == m-1)
			return 0;

		if (~dp[x][y])
			return dp[x][y];

		dp[x][y] = 1e9+7;
		if (x+1 < n)
			dp[x][y] = min(dp[x][y], solve(x+1, y, grid) + grid[x+1][y]);
		if (y+1 < m)
			dp[x][y] = min(dp[x][y], solve(x, y+1, grid) + grid[x][y+1]);

		return dp[x][y];
	}

	int minPathSum(vector<vector<int>>& grid) {
		n = grid.size();
		m = grid[0].size();
		dp.resize(n+1);
		for (int i=0; i<dp.size(); ++i)
			dp[i].resize(m+1, -1);

		return solve(0, 0, grid) + grid[0][0];
	}
};
