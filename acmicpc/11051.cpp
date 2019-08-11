#include <iostream>
using namespace std;
#define MAX 1001
#define MOD 10007

int dp[MAX][MAX];

int main()
{
	int n, k;

	cin >> n >> k;
	for (int i=0; i<=n; ++i) {
		dp[i][0] = dp[i][i] = 1;
		for (int j=1; j<=i-1; ++j) {
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
			dp[i][j] %= MOD;
		}
	}
	cout << dp[n][k] << '\n';

	return 0;
}
