#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001
#define MOD 1000000009

long long dp[MAX][MAX];

long long solve(int n, int m)
{
	if (n < 0 || m < 0)
		return 0;

	if (n == 0) {
		if (m == 0)
			return 1;
		else
			return 0;
	}

	if (dp[n][m] != -1)
		return dp[n][m];

	dp[n][m] = solve(n-1, m-1) % MOD;
	dp[n][m] += solve(n-2, m-1) % MOD;
	dp[n][m] += solve(n-3, m-1) % MOD;

	return dp[n][m];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n, m;

	cin >> t;
	memset(dp, -1, sizeof(dp));
	while (t--) {
		cin >> n >> m;
		cout << solve(n, m) % MOD << '\n';
	}

	return 0;
}
