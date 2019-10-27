#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101

int n, t;
int k[MAX], s[MAX];
int dp[MAX][10001];

int solve(int cur, int time)
{
	if (cur == n)
		return 0;

	if (dp[cur][time] != -1)
		return dp[cur][time];

	dp[cur][time] = solve(cur+1, time);
	if (time >= k[cur])
		dp[cur][time] = max(dp[cur][time], solve(cur+1, time - k[cur]) + s[cur]);

	return dp[cur][time];
}

int main()
{
	cin >> n >> t;
	for (int i=0; i<n; ++i)
		cin >> k[i] >> s[i];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, t) << '\n';

	return 0;
}
