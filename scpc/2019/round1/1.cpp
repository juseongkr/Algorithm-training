#include <iostream>
using namespace std;
#define MAX 1000001

int dp[MAX], arr[MAX];

int solve(int n)
{
	if (n == 0 || n == 1)
		return dp[n] = 0;
	if (n == 2)
		return dp[n] = 1;
	if (n == 3)
		return dp[n] = 3;

	if (dp[n] != -1)
		return dp[n];

	if (n % 2 != 0)
		return dp[n] = solve(n+1) + 1;
	else
		return dp[n] = solve(n/2) + 1;
}

int main()
{
	int t, a, b;

	fill(dp, dp+MAX, -1);
	for (int i=0; i<=MAX; ++i)
		solve(i);
	for (int i=1; i<=MAX; ++i)
		arr[i] = dp[i] + arr[i-1];

	scanf("%d", &t);
	for (int c=1; c<=t; ++c) {
		scanf("%d %d", &a, &b);

		int sum = arr[b] - arr[a-1];

		printf("Case #%d\n%d\n", c, sum);
	}

	return 0;
}
