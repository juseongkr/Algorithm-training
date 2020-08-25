#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100001
const int MOD = 1e9+9;

int T, n;
int dp[MAX][2];

int solve(int n, bool m)
{
	if (n < 0)
		return 0;

	if (n == 0)
		return m;

	if (~dp[n][m])
		return dp[n][m];

	dp[n][m] = solve(n-1, !m) % MOD;
	dp[n][m] = (dp[n][m] + solve(n-2, !m)) % MOD;
	dp[n][m] = (dp[n][m] + solve(n-3, !m)) % MOD;

	return dp[n][m];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	memset(dp, -1, sizeof(dp));
	while (T--) {
		cin >> n;
		cout << solve(n, 0) % MOD << " " << solve(n, 1) % MOD << '\n';
	}

	return 0;
}
