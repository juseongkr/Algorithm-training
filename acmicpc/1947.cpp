#include <iostream>
using namespace std;
#define MOD 1000000000

long long dp[1000001];

int main()
{
	int n;

	cin >> n;
	dp[2] = 1;
	for (int i=3; i<=n; ++i)
		dp[i] = ((i-1) * (dp[i-1] + dp[i-2])) % MOD;

	cout << dp[n] << '\n';

	return 0;
}
