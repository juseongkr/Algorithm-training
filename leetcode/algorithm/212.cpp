class Solution {
public:
	int n, m;
	const int dx[4] = {0, 1, 0, -1};
	const int dy[4] = {1, 0, -1, 0};

	bool solve(int x, int y, int cnt, vector<vector<char>> &board, string &word) {
		if (cnt == word.length()-1)
			return true;

		char temp = board[x][y];
		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] != word[cnt+1])
				continue;

			board[x][y] = '-';
			if (solve(nx, ny, cnt+1, board, word))
				return true;
			board[x][y] = temp;
		}
		return false;
	}

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		n = board.size();
		m = board[0].size();

		vector<string> ans;
		vector<vector<char>> origin = board;
		for (auto word : words) {
			board = origin;
			for (int i=0; i<n; ++i) {
				for (int j=0; j<m; ++j) {
					if (board[i][j] == word[0] && solve(i, j, 0, board, word)) {
						ans.push_back(word);
						break;
					}
				}
			}
		}
		ans.erase(unique(ans.begin(), ans.end()), ans.end());

		return ans;
	}
};
