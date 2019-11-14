#include <iostream>
using namespace std;
#define MAX 10001
const int MOD = 1e9+7;

int dp[MAX];

int main()
{
	int n, m;

	cin >> n >> m;
	dp[0] = dp[1] = 1;
	for (int i=2; i<=n; ++i) {
		dp[i] = dp[i-1];
		if (i-m >= 0)
			dp[i] += dp[i-m];
		dp[i] %= MOD;
	}
	cout << dp[n] << '\n';

	return 0;
}
