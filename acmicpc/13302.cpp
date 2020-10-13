#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101
const int INF = 1e9+7;

int n, m, k;
bool no[MAX];
int dp[MAX][MAX];

int solve(int cur, int ex)
{
	if (cur > n)
		return 0;

	if (~dp[cur][ex])
		return dp[cur][ex];

	dp[cur][ex] = INF;
	if (no[cur]) {
		dp[cur][ex] = min(dp[cur][ex], solve(cur+1, ex));
	} else {
		if (ex < 3)
			dp[cur][ex] = min(dp[cur][ex], solve(cur+1, ex) + 10000);
		else
			dp[cur][ex] = min(dp[cur][ex], solve(cur+1, ex-3));
	}

	dp[cur][ex] = min(dp[cur][ex], solve(cur+3, ex+1) + 25000);
	dp[cur][ex] = min(dp[cur][ex], solve(cur+5, ex+2) + 37000);

	return dp[cur][ex];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> k;
		no[k] = 1;
	}

	memset(dp, -1, sizeof(dp));

	cout << solve(1, 0) << '\n';

	return 0;
}
