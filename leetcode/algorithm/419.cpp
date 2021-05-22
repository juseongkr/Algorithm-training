class Solution {
public:
	const int dx[4] = {0, 1, 0, -1};
	const int dy[4] = {1, 0, -1, 0};
	vector<vector<char>> map;
	bool visit[201][201];
	int n, m;

	void dfs(int x, int y) {
		if (visit[x][y])
			return;
		visit[x][y] = 1;

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] != 'X')
				continue;
			dfs(nx, ny);
		}
	}

	int countBattleships(vector<vector<char>>& board) {
		int cnt = 0;
		map = board;
		n = board.size();
		m = board[0].size();
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				if (!visit[i][j] && board[i][j] == 'X') {
					dfs(i, j);
					cnt++;
				}
			}
		}

		return cnt;
	}
};
