#include <iostream>
#include <cstring>
using namespace std;
#define MAX 501
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m;
int map[MAX][MAX];
int dp[MAX][MAX];

int solve(int x, int y)
{
	if (x == n-1 && y == m-1)
		return 1;

	if (~dp[x][y])
		return dp[x][y];

	dp[x][y] = 0;
	for (int i=0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;

		if (map[x][y] > map[nx][ny])
			dp[x][y] += solve(nx, ny);
	}
	return dp[x][y];
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';

	return 0;
}
