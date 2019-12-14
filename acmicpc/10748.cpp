#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101
const int MOD = 1e9+7;

int n, m, k;
int map[MAX][MAX], dp[MAX][MAX];

int solve(int x, int y)
{
	if (x == n-1 && y == m-1)
		return 1;

	if (dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = 0;
	for (int i=1; i<n; ++i)
		for (int j=1; j<m; ++j)
			if (x+i < n && y+j < m && map[x][y] != map[x+i][y+j])
				dp[x][y] = (dp[x][y] + solve(x+i, y+j)) % MOD;

	return dp[x][y];
}

int main()
{
	cin >> n >> m >> k;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';

	return 0;
}
