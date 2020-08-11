class Solution {
public:
	vector<vector<int>> map;
	vector<vector<int>> dp;
	const int dx[4] = {0, 1, 0, -1};
	const int dy[4] = {1, 0, -1, 0};
	int n, m;

	int dfs(int x, int y) {
		if (~dp[x][y])
			return dp[x][y];

		dp[x][y] = 1;
		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[x][y] >= map[nx][ny])
				continue;

			dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
		}

		return dp[x][y];
	}

	int longestIncreasingPath(vector<vector<int>>& matrix) {
		n = matrix.size();
		if (n == 0)
			return 0;
		m = matrix[0].size();

		dp.resize(n+1, vector<int>(m+1, -1));
		map = matrix;

		int ans = 0;
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				ans = max(ans, dfs(i, j));

		return ans;
	}
};
