#include <iostream>
#include <cstring>
using namespace std;

int t;
string s;
int board[10][10];
bool check[3][10][10];

int square(int x, int y) { return (x / 3) * 3 + (y / 3); }

bool solve(int k)
{
	if (k == 9*9)
		return true;

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

bool impos(int x, int y)
{
	int num[10];
	fill(num, num+10, 0);
	for (int i=x; i<x+3; ++i)
		for (int j=y; j<y+3; ++j)
			num[board[i][j]]++;

	for (int i=1; i<10; ++i)
		if (num[i] > 1)
			return true;
	return false;
}

bool impos2()
{

	int num[10];
	fill(num, num+10, 0);
	for (int i=0; i<9; ++i) {
		fill(num, num+10, 0);
		for (int j=0; j<9; ++j)
			num[board[i][j]]++;
		for (int i=1; i<10; ++i)
			if (num[i] > 1)
				return true;
	}

	
	fill(num, num+10, 0);
	for (int i=0; i<9; ++i) {
		fill(num, num+10, 0);
		for (int j=0; j<9; ++j)
			num[board[j][i]]++;
		for (int i=1; i<10; ++i)
			if (num[i] > 1)
				return true;
	}

	return false;
}

int main()
{
	cin >> t;
	while (t--) {
		memset(board, 0, sizeof(board));
		memset(check, 0, sizeof(check));
		for (int i=0; i<9; ++i) {
			cin >> s;
			for (int j=0; j<9; ++j) {
				board[i][j] = s[j]-'0';
				if (board[i][j]) {
					check[0][i][board[i][j]] = true;
					check[1][j][board[i][j]] = true;
					check[2][square(i, j)][board[i][j]] = true;
				}
			}
		}

		bool flag = false;
		for (int i=0; i<9; i+=3)
			for (int j=0; j<9; j+=3)
				if (impos(i, j))
					flag = true;

		if (flag) {
			cout << "Could not complete this grid.\n";
		} else if (impos2()) {
			cout << "Could not complete this grid.\n";
		} else if (!solve(0)) {
			cout << "Could not complete this grid.\n";
		} else {
			for (int i=0; i<9; ++i) {
				for (int j=0; j<9; ++j)
					cout << board[i][j];
				cout << '\n';
			}
		}
		cout << '\n';
	}

	return 0;
}
