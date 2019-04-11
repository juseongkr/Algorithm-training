#include <iostream>
using namespace std;

int dp[10001], wine[10001];

int dfs(int n)
{
	if (n < 3)
		return dp[n];
	else if (dp[n])
		return dp[n];
	dp[n] = max(dfs(n-1), max(dfs(n-2) + wine[n], dfs(n-3) + wine[n-1] + wine[n]));
	return dp[n];
}

int main()
{
	int n;
	
	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
		scanf("%d", &wine[i]);

	dp[1] = wine[1];
	dp[2] = wine[2] + dp[1];

	printf("%d\n", dfs(n));

	return 0;
}
