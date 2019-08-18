#include <iostream>
#include <cstring>
using namespace std;
#define MAX 301

int n, m;
int map[MAX][MAX];
int dp[MAX][MAX];

int solve(int x, int y)
{
	if (x == n-1 && y == m-1)
		return 0;

	if (dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = 1e9+7;
	for (int i=0; i<=map[x][y]; ++i) {
		if (x + i < n)
			dp[x][y] = min(dp[x][y], solve(x+i, y) + 1);
		if (y + i < m)
			dp[x][y] = min(dp[x][y], solve(x, y+i) + 1);
	}

	return dp[x][y];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';

	return 0;
}
