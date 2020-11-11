class Solution {
public:
	const int dx[2] = {1, 0};
	const int dy[2] = {0, 1};
	int dp[101][101];

	int solve(int x, int y, vector<vector<int>> &map) {
		int m = map.size();
		int n = map[0].size();

		if (x == m-1 && y == n-1)
			return 1;

		if (~dp[x][y])
			return dp[x][y];

		dp[x][y] = 0;
		for (int i=0; i<2; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n || map[nx][ny])
				continue;

			dp[x][y] += solve(nx, ny, map);
		}

		return dp[x][y];
	}

	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid[0][0])
			return 0;

		memset(dp, -1, sizeof(dp));
		return solve(0, 0, obstacleGrid);
	}
};
