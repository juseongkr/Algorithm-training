#include <iostream>
using namespace std;

int dp[301], s[301];

int dfs(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return s[1];
	else if (n == 2)
		return s[1] + s[2];
	if (dp[n])
		return dp[n];

	dp[n] = max(dfs(n-2) + s[n], dfs(n-3) + s[n-1] + s[n]);
	return dp[n];
}

int main()
{
	int n;

	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
		scanf("%d", &s[i]);

	printf("%d\n", dfs(n));

	return 0;
}
