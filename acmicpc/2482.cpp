#include <iostream>
using namespace std;
#define MAX 1001
const int MOD = 1e9+3;

int n, k;
int dp[MAX][MAX];

int main()
{
	cin >> n >> k;
	for (int i=1; i<=n; ++i)
		dp[i][1] = i;

	for (int i=4; i<=n; ++i)
		for (int j=2; j<=i/2; ++j)
			dp[i][j] = (dp[i-2][j-1] + dp[i-1][j]) % MOD;

	cout << dp[n][k] << '\n';

	return 0;
}
