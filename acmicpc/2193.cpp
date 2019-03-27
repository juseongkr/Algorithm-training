#include <iostream>
using namespace std;

long long dp[91] = {0, 1, };

long long solve(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	if (dp[n] != 0)
		return dp[n];

	dp[n] = solve(n-2) + solve(n-1);
	return dp[n];
}

int main()
{
	int n;

	scanf("%d", &n);
	printf("%lld\n", solve(n));

	return 0;
}
