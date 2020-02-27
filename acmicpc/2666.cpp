#include <iostream>
#include <cstring>
using namespace std;
#define MAX 21

int n, m, a, b;
int num[MAX];
int dp[MAX][MAX][MAX];

int solve(int cur, int x, int y)
{
	if (cur == m)
		return 0;

	if (~dp[cur][x][y])
		return dp[cur][x][y];

	int X = solve(cur+1, num[cur], y) + abs(num[cur] - x);
	int Y = solve(cur+1, x, num[cur]) + abs(num[cur] - y);

	return dp[cur][x][y] = min(X, Y);
}

int main()
{
	cin >> n >> a >> b >> m;
	for (int i=0; i<m; ++i)
		cin >> num[i];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, a, b) << '\n';

	return 0;
}
