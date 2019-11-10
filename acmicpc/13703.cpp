#include <iostream>
#include <cstring>
using namespace std;
#define MAX 64

int n, k;
long long dp[MAX*2][MAX];

long long solve(int i, int t)
{
	if (i <= 0)
		return 0;

	if (t <= 0)
		return 1;

	if (dp[i][t] != -1)
		return dp[i][t];

	return dp[i][t] = solve(i-1, t-1) + solve(i+1, t-1);
}

int main()
{
	cin >> k >> n;

	memset(dp, -1, sizeof(dp));
	cout << solve(k, n) << '\n';

	return 0;
}
