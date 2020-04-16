#include <iostream>
#include <cstring>
using namespace std;
#define MAX 301

int n, m, k;
int dp[MAX][21], table[MAX][21], ans[MAX][21];

int solve(int left, int cur)
{
	if (cur == m)
		return 0;

	if (~dp[left][cur])
		return dp[left][cur];

	ans[left][cur] = 0;
	dp[left][cur] = solve(left, cur+1);
	for (int i=1; i<=left; ++i) {
		int next = solve(left-i, cur+1) + table[i][cur];
		if (dp[left][cur] < next) {
			ans[left][cur] = i;
			dp[left][cur] = next;
		}
	}
	return dp[left][cur];
}

void tracing(int left, int cur)
{
	if (cur == m)
		return;
	cout << ans[left][cur] << " ";
	tracing(left - ans[left][cur], cur+1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> k;
		for (int j=0; j<m; ++j)
			cin >> table[k][j];
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(n, 0) << '\n';
	tracing(n, 0);

	return 0;
}
