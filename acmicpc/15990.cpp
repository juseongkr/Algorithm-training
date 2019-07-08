#include <iostream>
using namespace std;
#define MAX 100001
#define MOD 1000000009

long long dp[MAX][4];

int main()
{
	int t, n;

	dp[1][1] = dp[2][2] = 1;
	dp[3][1] = dp[3][2] = dp[3][3] = 1;
	for (int i=4; i<MAX; ++i) {
		dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % MOD;
		dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % MOD;
		dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % MOD;
	}

	cin >> t;
	while (t--) {
		cin >> n;
		long long ans = (dp[n][1] + dp[n][2] + dp[n][3]) % MOD;
		cout << ans << '\n';
	}

	return 0;
}
