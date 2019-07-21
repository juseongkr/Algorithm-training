#include <iostream>
using namespace std;
#define MAX 1002
#define MIN_VAL -9999999

int n, m;
int map[MAX][MAX], visit[MAX][MAX];
long long dp[MAX][MAX][3];

long long solve(int y, int x, int d)
{
	if (y == n && x == m)
		return map[y][x];

	if (dp[y][x][d] != MIN_VAL)
		return dp[y][x][d];

	long long a = MIN_VAL, b = MIN_VAL, c = MIN_VAL;
	visit[y][x] = 1;
	if (!visit[y+1][x] && y+1 <= n)
		a = solve(y+1, x, 0);

	if (!visit[y][x+1] && x+1 <= m)
		b = solve(y, x+1, 1);

	if (!visit[y][x-1] && x-1 > 0)
		c = solve(y, x-1, 2);
	visit[y][x] = 0;

	dp[y][x][d] = max(a, max(b, c)) + map[y][x];

	return dp[y][x][d];
}

int main()
{
	cin >> n >> m;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			cin >> map[i][j];
			dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = MIN_VAL;
		}
	}
	cout << solve(1, 1, 0) << '\n';

	return 0;
}
