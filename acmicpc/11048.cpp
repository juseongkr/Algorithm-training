#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001

int dp[MAX][MAX], map[MAX][MAX];
int n, m;

int solve(int y, int x)
{
	if (y < 0 || x < 0 || y > n || x > m)
		return 0;

	if (dp[y][x] != -1)
		return dp[y][x];

	dp[y][x] = 0;
	dp[y][x] += max(solve(y-1, x-1), max(solve(y-1, x), solve(y, x-1))) + map[y][x];
	return dp[y][x];
}

int main()
{
	cin >> n >> m;
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=m; ++j)
			cin >> map[i][j];

	memset(dp, -1, sizeof(dp));
	cout << solve(n, m) << '\n';

	return 0;
}
