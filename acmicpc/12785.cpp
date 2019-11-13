#include <iostream>
#include <cstring>
using namespace std;
#define MAX 201
const int MOD = 1e6+7;

int n, m, X, Y;
int dp[MAX][MAX][2];

int solve(int x, int y, int k)
{
	if (x == n && y == m)
		return k;

	if (x == X && y == Y)
		k = 1;

	if (dp[x][y][k] != -1)
		return dp[x][y][k];

	dp[x][y][k] = 0;
	if (x < n)
		dp[x][y][k] += solve(x+1, y, k);
	if (y < m)
		dp[x][y][k] += solve(x, y+1, k);

	dp[x][y][k] %= MOD;
	return dp[x][y][k];
}

int main()
{
	cin >> n >> m >> X >> Y;

	memset(dp, -1, sizeof(dp));
	cout << solve(1, 1, 0) << '\n';

	return 0;
}
