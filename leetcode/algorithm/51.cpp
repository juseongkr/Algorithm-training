class Solution {
public:
	vector<vector<int>> ans;
	vector<bool> check[3];
	vector<int> board;

	void solve(int x, int n) {
		if (x == n) {
			ans.push_back(board);
			return;
		}

		for (int i=0; i<n; ++i) {
			if (check[0][i] || check[1][x+i] || check[2][x+n-i])
				continue;

			check[0][i] = check[1][x+i] = check[2][x+n-i] = 1;
			board.push_back(i);
			solve(x+1, n);
			board.pop_back();
			check[0][i] = check[1][x+i] = check[2][x+n-i] = 0;
		}
	}

	vector<vector<string>> solveNQueens(int n) {
		for (int i=0; i<3; ++i)
			check[i].resize(2*n, 0);

		solve(0, n);

		vector<vector<string>> ret(ans.size(), vector<string>(n, string(n, '.')));
		for (int i=0; i<ans.size(); ++i) {
			for (int j=0; j<n; ++j) {
				int x = ans[i][j];
				ret[i][x][j] = 'Q';
			}
		}

		return ret;
	}
};
