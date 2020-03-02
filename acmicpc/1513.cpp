#include <iostream>
#include <cstring>
using namespace std;
#define MAX 51
const int MOD = 1e6+7;

int n, m, c, x, y;
int game[MAX][MAX];
int dp[MAX][MAX][MAX][MAX];

int solve(int x, int y, int cur, int left)
{
	if (x > n || y > m)
		return 0;

	if (x == n && y == m) {
		if (game[x][y])
			return left == 1 && game[x][y] > cur;
		else
			return left == 0;
	}

	if (~dp[x][y][cur][left])
		return dp[x][y][cur][left];

	if (game[x][y]) {
		if (!left || game[x][y] < cur) {
			return 0;
		} else {
			cur = game[x][y];
			left--;
		}
	}

	dp[x][y][cur][left] = solve(x+1, y, cur, left) + solve(x, y+1, cur, left);

	return dp[x][y][cur][left] %= MOD;
}

int main()
{
	cin >> n >> m >> c;
	for (int i=0; i<c; ++i) {
		cin >> x >> y;
		game[x][y] = i+1;
	}
	
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<=c; ++i)
		cout << solve(1, 1, 0, i) << ' ';

	return 0;
}
