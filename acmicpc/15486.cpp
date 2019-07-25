#include <iostream>
using namespace std;
#define MAX 1500001

int n;
int t[MAX], p[MAX], dp[MAX];

int solve(int idx)
{
	if (idx == n)
		return 0;

	if (dp[idx] != -1)
		return dp[idx];

	dp[idx] = solve(idx+1);
	if (idx + t[idx] <= n)
		dp[idx] = max(dp[idx], solve(idx + t[idx]) + p[idx]);

	return dp[idx];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> t[i] >> p[i];

	fill(dp, dp+MAX, -1);
	cout << solve(0) << '\n';

	return 0;
}
