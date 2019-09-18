#include <iostream>
using namespace std;
#define MAX 1001
const int MOD = 1e9+7;

long long dp[MAX][MAX];

int main()
{
	int n, m;

	cin >> n >> m;
	dp[1][1] = 1;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			dp[i][j] += dp[i-1][j-1] + dp[i-1][j] + dp[i][j-1];
			dp[i][j] %= MOD;
		}
	}
	cout << dp[n][m] << '\n';

	return 0;
}
