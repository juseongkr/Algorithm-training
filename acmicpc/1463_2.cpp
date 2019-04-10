#include <iostream>
using namespace std;

long long dp[1000001];

long long dfs(long long n)
{
	if (n == 0 || n == 1)
		return 0;
	else if (n == 2 || n == 3)
		return 1;
	if (dp[n])
		return dp[n];
	
	if (n%3 == 0)
		dp[n] = min(dfs(n/3), dfs(n-1)) + 1;
	else if (n%2 == 0)
		dp[n] = min(dfs(n/2), dfs(n-1)) + 1;
	else
		dp[n] = dfs(n-1) + 1;
	return dp[n];
}

int main()
{
	long long n;
	
	scanf("%lld", &n);
	printf("%lld\n", dfs(n));

	return 0;
}
