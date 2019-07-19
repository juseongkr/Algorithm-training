#include <iostream>
using namespace std;

int board[10][10];
bool check[3][10][10];

int square(int x, int y) { return (x / 3) * 3 + (y / 3); }

bool solve(int k)
{
	if (k == 9*9) {
		for (int i=0; i<9; ++i) {
			for (int j=0; j<9; ++j)
				cout << board[i][j] << " ";
			cout << '\n';
		}
		return true;
	}

	int x = k / 9;
	int y = k % 9;
	if (board[x][y]) {
		return solve(k + 1);
	} else {
		for (int i=1; i<=9; ++i) {
			if (check[0][x][i] || check[1][y][i] ||	check[2][square(x, y)][i])
				continue;

			check[0][x][i] = check[1][y][i] = check[2][square(x, y)][i] = true;
			board[x][y] = i;
			if (solve(k + 1))
				return true;
			board[x][y] = 0;
			check[0][x][i] = check[1][y][i] = check[2][square(x, y)][i] = false;
		}
	}
	return false;
}

int main()
{
	for (int i=0; i<9; ++i) {
		for (int j=0; j<9; ++j) {
			cin >> board[i][j];
			if (board[i][j]) {
				check[0][i][board[i][j]] = true;
				check[1][j][board[i][j]] = true;
				check[2][square(i, j)][board[i][j]] = true;
			}
		}
	}

	solve(0);

	return 0;
}
