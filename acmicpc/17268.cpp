#include <iostream>
using namespace std;
#define MOD 987654321

long long dp[5001];

int main()
{
	int n;

	cin >> n;
	n /= 2;
	dp[0] = 1;
	for (int i=1; i<=n; ++i) {
		for (int j=0; j<i; ++j) {
			dp[i] += dp[j] * dp[i-j-1];
			dp[i] %= MOD;
		}
	}
	cout << dp[n] << '\n';

	return 0;
}
