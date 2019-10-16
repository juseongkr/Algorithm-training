#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1501

int n;
int dp[MAX][MAX], map[MAX][MAX];

int solve(int x, int y)
{
	int go = max(x, y) + 1;
	if (go > n)
		return 0;

	if (dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = min(solve(go, y) + map[go][x], solve(x, go) + map[y][go]);
	return dp[x][y];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			cin >> map[i][j];

	memset(dp, -1, sizeof(dp));
	cout << solve(1, 1) << '\n';

	return 0;
}
