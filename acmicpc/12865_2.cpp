#include <iostream>
#include <cstring>
using namespace std;
#define MAX_LEN 101
#define MAX_WEIGHT 100001

int dp[MAX_LEN][MAX_WEIGHT];
int w[MAX_LEN], v[MAX_LEN];
int n, k;

int solve(int cur, int weight)
{
	if (cur == n)
		return 0;

	if (dp[cur][weight] != -1)
		return dp[cur][weight];

	dp[cur][weight] = solve(cur+1, weight);
	if (weight >= w[cur])
		dp[cur][weight] = max(dp[cur][weight], solve(cur+1, weight-w[cur]) + v[cur]);

	return dp[cur][weight];
}

int main()
{
	cin >> n >> k;

	memset(dp, -1, sizeof(dp));
	for (int i=0; i<n; ++i)
		cin >> w[i] >> v[i];

	cout << solve(0, k) << '\n';

	return 0;
}
