class Solution {
public:
	bool square(int x, int y, vector<vector<char>> &board) {
		int check[10];
		fill(check, check+10, 0);
		for (int i=x; i<x+3; ++i) {
			for (int j=y; j<y+3; ++j) {
				int num = board[i][j] == '.' ? 0 : board[i][j]-'0';
				check[num]++;
			}
		}

		for (int i=1; i<10; ++i)
			if (check[i] >= 2)
				return true;

		return false;
	}

	bool isValidSudoku(vector<vector<char>>& board) {
		int check[10];
		for (int i=0; i<board.size(); ++i) {
			fill(check, check+10, 0);
			for (int j=0; j<board[0].size(); ++j) {
				int num = board[i][j] == '.' ? 0 : board[i][j]-'0';
				check[num]++;
			}
			for (int j=1; j<10; ++j)
				if (check[j] >= 2)
					return false;
		}

		for (int i=0; i<board.size(); ++i) {
			fill(check, check+10, 0);
			for (int j=0; j<board[0].size(); ++j) {
				int num = board[j][i] == '.' ? 0 : board[j][i]-'0';
				check[num]++;
			}
			for (int j=1; j<10; ++j)
				if (check[j] >= 2)
					return false;
		}

		for (int i=0; i<board.size(); i+=3) {
			for (int j=0; j<board[0].size(); j+=3) {
				if (square(i, j, board))
					return false;
			}
		}

		return true;
	}
};
