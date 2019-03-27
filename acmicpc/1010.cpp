#include <iostream>
#include <string.h>
using namespace std;

int dp[31][31];

int solve(int n, int m)
{
	if (n == 0 || n == m)
		return 1;

	if (dp[n][m] != 0)
		return dp[n][m];

	dp[n][m] = solve(n, m-1) + solve(n-1, m-1);

	return dp[n][m];
}

int main()
{
	int num, n, m;

	scanf("%d", &num);

	for (int i=0; i<num; ++i) {
		memset(dp, 0, sizeof(dp));
		scanf("%d %d", &n, &m);
		printf("%d\n", solve(n, m));
	}
	return 0;
}
