class Solution {
public:
	const int dx[4] = {0, 1, 0, -1};
	const int dy[4] = {1, 0, -1, 0};

	void solve(vector<vector<char>>& board) {
		int n = board.size();
		if (n == 0)
			return;
		int m = board[0].size();
		vector<vector<char>> map(n+3, vector<char>(m+3, 'O'));
		vector<vector<bool>> visit(n+3, vector<bool>(m+3, false));

		for (int i=1; i<=n; ++i)
			for (int j=1; j<=m; ++j)
				map[i][j] = board[i-1][j-1];

		queue<pair<int, int>> que;
		que.push({0, 0});
		visit[0][0] = 1;

		while (!que.empty()) {
			auto [x, y] = que.front();
			que.pop();

			for (int i=0; i<4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx > n+1 || ny < 0 || ny > m+1 || visit[nx][ny] || map[nx][ny] == 'X')
				continue;

				visit[nx][ny] = 1;
				que.push({nx, ny});
			}
		}

		for (int i=1; i<=n; ++i)
			for (int j=1; j<=m; ++j)
				if (!visit[i][j])
					board[i-1][j-1] = 'X';
	}
};
