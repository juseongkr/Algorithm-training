#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100001
#define ll long long
const ll INF = 1e18+7;
const int dx[4] = {0, 1, -1, 0};
const int dy[4] = {1, 0, 0, -1};

int n, sx, sy;
int x[MAX], y[MAX];
ll dp[MAX][4];

ll solve(int cur, int k)
{
	if (cur == n)
		return 0;

	if (~dp[cur][k])
		return dp[cur][k];

	dp[cur][k] = INF;
	for (int i=0; i<4; ++i) {
		int nx = x[cur] + dx[i];
		int ny = y[cur] + dy[i];

		if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX)
			continue;

		ll ret = 0;
		if (cur) {
			ret = solve(cur+1, i) + abs(x[cur-1] + dx[k] - nx) + abs(y[cur-1] + dy[k] - ny);
		} else {
			ret = solve(cur+1, i) + abs(sx - nx) + abs(sy - ny);
		}
		dp[cur][k] = min(dp[cur][k], ret);
	}

	return dp[cur][k];
}

int main()
{
	cin >> n >> sx >> sy;
	for (int i=0; i<n; ++i)
		cin >> x[i] >> y[i];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';

	return 0;
}
