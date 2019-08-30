#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101
#define MOD 100000

int w, h;
int dp[MAX][MAX][2];

int solve(int n, int m, bool k)
{
	if (n >= w && m >= h)
		return 1;

	if (n > w || m > h)
		return 0;

	if (dp[n][m][k] != -1)
		return dp[n][m][k];

	dp[n][m][k] = 0;
	if (k) {
		dp[n][m][k] = solve(n+2, m, false) + solve(n, m+1, true);
		dp[n][m][k] %= MOD;
	} else {
		dp[n][m][k] = solve(n, m+2, true) + solve(n+1, m, false);
		dp[n][m][k] %= MOD;
	}

	return dp[n][m][k] %= MOD;
}

int main()
{
	cin >> w >> h;

	memset(dp, -1, sizeof(dp));
	cout << (solve(2, 1, false) + solve(1, 2, true)) % MOD << '\n';

	return 0;
}
