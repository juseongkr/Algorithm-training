#include <iostream>
using namespace std;
#define MOD 10007

int main()
{
	int dp[10];
	int n;

	cin >> n;
	fill(dp, dp+10, 1);
	for (int i=1; i<n; ++i)
		for (int j=1; j<10; ++j)
			dp[j] = (dp[j] + dp[j-1]) % MOD;

	long long ans = 0;
	for (int i=0; i<10; ++i)
		ans = (ans + dp[i]) % MOD;

	cout << ans << '\n';

	return 0;
}
