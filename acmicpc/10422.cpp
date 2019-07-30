#include <iostream>
using namespace std;
#define MAX 5001
#define MOD 1000000007

long long dp[MAX];

int main()
{
	int t, n;

	dp[0] = dp[2] = 1;
	for (int i=3; i<MAX; ++i) {
		for (int j=2; j<=i; ++j) {
			if (j-2 >= 0 && i-j >= 0) {
				dp[i] += dp[j-2] * dp[i-j];
				dp[i] = dp[i] % MOD;
			}
		}
	}

	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}
