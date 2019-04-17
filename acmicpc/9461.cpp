#include <iostream>
using namespace std;

int main()
{
	long long dp[101] = {0, 1, 1, 1, 2, 2, 3};
	int t, n;

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i=6; i<=n; ++i)
			dp[i] = dp[i-1] + dp[i-5];
		printf("%lld\n", dp[n]);
	}

	return 0;
}
