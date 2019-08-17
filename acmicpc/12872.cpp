#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101
#define MOD 1000000007

int n, m, p;
long long dp[MAX][MAX][MAX];

long long solve(int cur, int x, int y)
{
	if (cur == p) {
		if (y == 0)
			return 1;
		else
			return 0;
	}

	if (dp[cur][x][y] != -1)
		return dp[cur][x][y];

	dp[cur][x][y] = 0;
	if (y > 0)
		dp[cur][x][y] += solve(cur+1, x+1, y-1) * y;
	if (x > m)
		dp[cur][x][y] += solve(cur+1, x, y) * (x - m);

	return dp[cur][x][y] %= MOD;
}

int main()
{
	cin >> n >> m >> p;

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0, n) << '\n';

	return 0;
}
