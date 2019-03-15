#include <iostream>
#include <string.h>
#define fill(a, x)	memset(a, x, sizeof(a))
using namespace std;

int path[501][501];
int dp[501][501];
int a[4] = {-1, 0, 1, 0};
int b[4] = {0, -1, 0, 1};
int w, h;

int dfs(int x, int y)
{
	if (x < 0 || y < 0 || x >= w || y >= h)
		return 0;
	if (x == 0 && y == 0)
		return 1;
	if (dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = 0;
	for (int i=0; i<4; ++i) {
		if (path[x][y] < path[x + a[i]][y + b[i]])
			dp[x][y] += dfs(x + a[i], y + b[i]);
	}

	return dp[x][y];
}

int main()
{
	cin >> w >> h;
	fill(dp, -1);
	
	for (int i=0; i<w; ++i)
		for (int j=0; j<h; ++j)
			cin >> path[i][j];

	cout << dfs(w-1, h-1) << '\n';

	return 0;
}
