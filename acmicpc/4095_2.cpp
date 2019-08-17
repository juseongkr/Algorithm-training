#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001

int n, m;
int map[MAX][MAX], dp[MAX][MAX];

int solve(int x, int y)
{
	if (x >= n || y >= m)
		return 0;

	if (dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = 0;
	if (map[x][y] != 0)
		dp[x][y] = min(solve(x+1, y), min(solve(x, y+1), solve(x+1, y+1))) + 1;

	return dp[x][y];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		memset(dp, -1, sizeof(dp));
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				cin >> map[i][j];

		int ans = 0;
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				ans = max(ans, solve(i, j));

		cout << ans << '\n';
	}

	return 0;
}
