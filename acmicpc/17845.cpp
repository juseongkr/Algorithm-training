#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001

int n, k;
int l[MAX], t[MAX];
int dp[MAX][10001];

int solve(int cur, int time)
{
	if (cur == k)
		return 0;

	if (dp[cur][time] != -1)
		return dp[cur][time];

	dp[cur][time] = solve(cur+1, time);
	if (time >= t[cur])
		dp[cur][time] = max(dp[cur][time], solve(cur+1, time - t[cur]) + l[cur]);

	return dp[cur][time];
}

int main()
{
	cin >> n >> k;
	for (int i=0; i<k; ++i)
		cin >> l[i] >> t[i];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, n) << '\n';

	return 0;
}
