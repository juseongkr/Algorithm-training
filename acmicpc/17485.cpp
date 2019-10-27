#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001
const int INF = 1e9+7;
const int dx[3] = {1, 1, 1};
const int dy[3] = {-1, 0, 1};

int n, m;
int map[MAX][MAX];
int dp[MAX][MAX][3];

int solve(int x, int y, int d)
{
	if (x == n-1)
		return 0;

	if (dp[x][y][d] != -1)
		return dp[x][y][d];

	dp[x][y][d] = INF;
	for (int i=0; i<3; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m || d == i)
			continue;

		dp[x][y][d] = min(dp[x][y][d], solve(nx, ny, i) + map[nx][ny]);
	}

	return dp[x][y][d];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	int ans = INF;
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<m; ++i)
		for (int j=0; j<3; ++j)
			ans = min(ans, map[0][i] + solve(0, i, j));

	cout << ans << '\n';

	return 0;
}
