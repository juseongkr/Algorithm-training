#include <iostream>
using namespace std;
#define MAX 1000001
#define MOD 1000000009

long long dp[MAX];

int main()
{
	int t, n;

	dp[0] = dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i=4; i<MAX; ++i)
		dp[i] += (dp[i-1] + dp[i-2] + dp[i-3]) % MOD;

	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}
