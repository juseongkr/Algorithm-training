class Solution {
public:
	bool check[3][10][10];
	int square(int x, int y) { return (x / 3) * 3 + (y / 3); }

	bool solve(int k, vector<vector<char>> &board) {
		if (k == 9*9) {
			return true;
		}

		int x = k / 9;
		int y = k % 9;
		if (board[x][y] != '.') {
			return solve(k + 1, board);
		} else {
			for (int i=1; i<=9; ++i) {
				if (check[0][x][i] || check[1][y][i] ||	check[2][square(x, y)][i])
					continue;

				check[0][x][i] = check[1][y][i] = check[2][square(x, y)][i] = true;
				board[x][y] = i+'0';
				if (solve(k + 1, board))
					return true;
				board[x][y] = '.';
				check[0][x][i] = check[1][y][i] = check[2][square(x, y)][i] = false;
			}
		}
		return false;
	}

	void solveSudoku(vector<vector<char>>& board) {
		for (int i=0; i<9; ++i) {
			for (int j=0; j<9; ++j) {
				if (board[i][j] != '.') {
					check[0][i][board[i][j]-'0'] = true;
					check[1][j][board[i][j]-'0'] = true;
					check[2][square(i, j)][board[i][j]-'0'] = true;
				}
			}
		}

		solve(0, board);
	}
};
