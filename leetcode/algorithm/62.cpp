class Solution {
public:
	const int dx[2] = {1, 0};
	const int dy[2] = {0, 1};

	int dp[101][101];

	int solve(int x, int y, int m, int n) {
		if (x == m && y == n)
			return 1;

		if (~dp[x][y])
			return dp[x][y];

		dp[x][y] = 0;
		for (int i=0; i<2; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx > m || ny < 1 || ny > n)
				continue;

			dp[x][y] += solve(nx, ny, m, n);
		}

		return dp[x][y];
	}

	int uniquePaths(int m, int n) {
		memset(dp, -1, sizeof(dp));
		return solve(1, 1, m, n);
	}
};
