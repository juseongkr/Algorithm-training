#include <iostream>
using namespace std;

int dp[31];

int dfs(int n)
{
	if (n%2 != 0)
		return 0;
	else if (n == 0)
		return 1;
	else if (n == 2)
		return 3;
	if (dp[n] != -1)
		return dp[n];
	
	dp[n] = dfs(n-2) * 3;
	for (int i=0; i<n-3; ++i)
		dp[n] += dfs(i) * 2;

	return dp[n];
}

int main()
{
	int n;

	scanf("%d", &n);
	for (int i=0; i<31; ++i)
		dp[i] = -1;

	printf("%d\n", dfs(n));

	return 0;
}
