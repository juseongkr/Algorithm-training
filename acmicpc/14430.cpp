#include <iostream>
#include <cstring>
using namespace std;
#define MAX 301

int n, m;
int map[MAX][MAX];
int dp[MAX][MAX];

int solve(int x, int y)
{
	if (x > n || y > m)
		return 0;

	if (dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = map[x][y];
	dp[x][y] += max(solve(x, y+1), solve(x+1, y));

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
