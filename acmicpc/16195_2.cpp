#include <iostream>
using namespace std;
#define MAX 1001
#define MOD 1000000009

int n, m;
long long dp[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	dp[0][0] = 1;
	for (int i=1; i<MAX; ++i) {
		for (int j=1; j<=i; ++j) {
			if (i-1 >= 0)
				dp[i][j] += dp[i-1][j-1];

			if (i-2 >= 0)
				dp[i][j] += dp[i-2][j-1];

			if (i-3 >= 0)
				dp[i][j] += dp[i-3][j-1];

			dp[i][j] %= MOD;
		}
	}

	cin >> t;
	while (t--) {
		cin >> n >> m;
		long long ans = 0;
		for (int i=1; i<=m; ++i) {
			ans += dp[n][i];
			ans %= MOD;
		}
		cout << ans << '\n';
	}

	return 0;
}
