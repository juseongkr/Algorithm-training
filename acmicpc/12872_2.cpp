#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101
#define MOD 1000000007

int n, m, p;
long long dp[MAX][MAX];

long long solve(int cur, int x)
{
	int y = n-x;
	if (cur == p) {
		if (y == 0)
			return 1;
		else
			return 0;
	}

	if (dp[cur][x] != -1)
		return dp[cur][x];

	dp[cur][x] = 0;
	if (y > 0)
		dp[cur][x] += solve(cur+1, x+1) * y;
	if (x > m)
		dp[cur][x] += solve(cur+1, x) * (x - m);

	return dp[cur][x] %= MOD;
}

int main()
{
	cin >> n >> m >> p;

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';

	return 0;
}
