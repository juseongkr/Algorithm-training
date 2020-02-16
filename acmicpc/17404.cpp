#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001
const int INF = 1e9+7;

int n;
int color[MAX][3], dp[MAX][3][3];

int solve(int cur, int col, int last)
{
	if (cur == n && col != last)
		return 0;

	if (cur == n && col == last)
		return INF;

	if (~dp[cur][col][last])
		return dp[cur][col][last];

	dp[cur][col][last] = INF;
	for (int i=0; i<3; ++i)
		if (col != i)
			dp[cur][col][last] = min(dp[cur][col][last], solve(cur+1, i, last) + color[cur][i]);

	return dp[cur][col][last];
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		for (int j=0; j<3; ++j)
			cin >> color[i][j];

	memset(dp, -1, sizeof(dp));
	int ans = INF;
	for (int i=0; i<3; ++i)
		ans = min(ans, solve(1, i, i) + color[0][i]);

	cout << ans << '\n';

	return 0;
}
