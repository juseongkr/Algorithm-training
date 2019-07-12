#include <iostream>
using namespace std;
#define MAX 101

int main()
{
	long long dp[MAX];
	int n;

	cin >> n;
	for (int i=0; i<7; ++i)
		dp[i] = i;

	for (int i=7; i<=n; ++i)
		dp[i] = max(dp[i-5]*4, max(dp[i-4]*3, dp[i-3]*2));

	cout << dp[n] << '\n';

	return 0;
}
