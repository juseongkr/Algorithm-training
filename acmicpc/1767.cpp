#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101
#define MOD 1000001

int n, m, k;
long long dp[MAX][MAX][MAX];

long long solve(int n, int m, int k)
{
	if (k == 0)
		return 1;

	if (n <= 0 || m <= 0 || k <= 0)
		return 0;

	if (dp[n][m][k] != -1)
		return dp[n][m][k];

	dp[n][m][k] = solve(n-1, m, k) + \
		      solve(n-1, m-1, k-1) * m + \
		      solve(n-1, m-2, k-2) * m * (m-1) / 2 + \
		      solve(n-2, m-1, k-2) * m * (n-1);

	return dp[n][m][k] %= MOD;
}

int main()
{
	cin >> n >> m >> k;
	memset(dp, -1, sizeof(dp));
	cout << solve(n, m, k) << '\n';

	return 0;
}
