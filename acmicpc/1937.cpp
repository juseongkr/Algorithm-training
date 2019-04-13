#include <iostream>
using namespace std;

int n, cnt;
int map[501][501];
int dp[501][501];
int a[4] = {0, 1, 0, -1};
int b[4] = {1, 0, -1, 0};

int dfs(int x, int y)
{
	if (dp[x][y] != 0)
		return dp[x][y];

	dp[x][y] = 1;
	for (int i=0; i<4; ++i) {
		int next_x = x + a[i];
		int next_y = y + b[i];

		if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= n)
			continue;

		if (map[x][y] < map[next_x][next_y])
			dp[x][y] = max(dp[x][y], dfs(next_x, next_y) + 1);
	}
	return dp[x][y];
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			scanf("%d", &map[i][j]);

	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cnt = max(cnt, dfs(i, j));

	printf("%d\n", cnt);

	return 0;
}
