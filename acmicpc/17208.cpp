#include <iostream>
#include <cstring>
using namespace std;
#define MAX_VAL 301
#define MAX_LEN 101

int n, m, k;
int dp[MAX_LEN][MAX_VAL][MAX_VAL];
int cheese[MAX_LEN], fried[MAX_LEN];

int solve(int cur, int c, int f)
{
	if (cur == n)
		return 0;

	if (dp[cur][c][f] != -1)
		return dp[cur][c][f];

	dp[cur][c][f] = solve(cur+1, c, f);
	if (c >= cheese[cur] && f >= fried[cur])
		dp[cur][c][f] = max(dp[cur][c][f], solve(cur+1, c-cheese[cur], f-fried[cur]) + 1);
	return dp[cur][c][f];
}

int main()
{
	cin >> n >> m >> k;

	memset(dp, -1, sizeof(dp));
	for (int i=0; i<n; ++i)
		cin >> cheese[i] >> fried[i];

	cout << solve(0, m, k) << '\n';

	return 0;
}
