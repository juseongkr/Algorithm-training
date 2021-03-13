class Solution {
public:
	const int dx[4] = {0, 1, 0, -1};
	const int dy[4] = {1, 0, -1, 0};
	vector<vector<bool>> pacific, atlantic;
	bool visit[151][151];
	int n, m;

	void dfs(int x, int y, vector<vector<bool>>& visit, vector<vector<int>> &matrix) {
		visit[x][y] = 1;

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || visit[nx][ny])
				continue;

			if (matrix[x][y] <= matrix[nx][ny])
				dfs(nx, ny, visit, matrix);
		}
	}

	vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
		if (matrix.size() == 0)
			return {};

		n = matrix.size();
		m = matrix[0].size();
		pacific.resize(n, vector<bool>(m, false));
		atlantic.resize(n, vector<bool>(m, false));
		vector<vector<int>> ans;

		for (int i=0; i<n; ++i)
			if (!pacific[i][0])
				dfs(i, 0, pacific, matrix);

		for (int i=0; i<n; ++i)
			if (!atlantic[i][m-1])
				dfs(i, m-1, atlantic, matrix);

		for (int i=0; i<m; ++i)
			if (!pacific[0][i])
				dfs(0, i, pacific, matrix);

		for (int i=0; i<m; ++i)
			if (!atlantic[n-1][i])
				dfs(n-1, i, atlantic, matrix);

		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				if (pacific[i][j] && atlantic[i][j])
					ans.push_back({i, j});

		return ans;
	}
};
