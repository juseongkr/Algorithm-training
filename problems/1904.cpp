#include <iostream>
using namespace std;

#define MOD 15746
long long dp[1000001];

long long solve(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	if (dp[n] != 0)
		return dp[n];

	dp[n] = solve(n-2) + solve(n-1);
	dp[n] %= MOD;
	return dp[n];
}

int main()
{
	int n;

	scanf("%d", &n);
	printf("%lld\n", solve(n));

	return 0;
}
