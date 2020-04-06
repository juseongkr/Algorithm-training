#include <iostream>
#include <cstring>
using namespace std;
#define MAX 51

int T, n, k;
int board[MAX][MAX];
bool check[2][MAX][MAX];

bool latin()
{
	int sum = 0;
	for (int i=0; i<n; ++i)
		sum += board[i][i];
	return sum == k;
}

bool solve(int m, int t)
{
	if (m == n*n && latin()) {
		cout << "Case #" << t << ": POSSIBLE\n";
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j)
				cout << board[i][j] << " ";
			cout << '\n';
		}
		return true;
	}

	int x = m / n;
	int y = m % n;

	if (board[x][y]) {
		return solve(m+1, t);
	} else {
		for (int i=1; i<=n; ++i) {
			if (check[0][x][i] || check[1][y][i])
				continue;

			check[0][x][i] = check[1][y][i] = true;
			board[x][y] = i;

			int sum = 0;
			for (int j=0; j<n; ++j)
				sum += board[j][j];

			if (sum <= k && solve(m+1, t))
				return true;
			board[x][y] = 0;
			check[0][x][i] = check[1][y][i] = false;
		}
	}
	return false;
}

int main()
{
	cin >> T;
	for (int t=1; t<=T; ++t) {
		cin >> n >> k;
		memset(check, 0, sizeof(check));
		memset(board, 0, sizeof(board));
		if (!solve(0, t))
			cout << "Case #" << t << ": IMPOSSIBLE\n";
	}

	return 0;
}
