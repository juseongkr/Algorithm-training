#include <iostream>
#include <cstring>
using namespace std;
#define MAX 10
#define INF 16000001

int n;
int map[MAX][MAX];
int dp[MAX][1<<MAX];

int solve(int cur, int visit)
{
	if (visit == (1 << n) - 1) {
		if (map[cur][0])
			return map[cur][0];
		else
			return INF;
	}

	if (dp[cur][visit] != -1)
		return dp[cur][visit];

	dp[cur][visit] = INF;
	for (int i=0; i<n; ++i) {
		if (visit & (1 << i) || !map[cur][i])
			continue;
		dp[cur][visit] = min(dp[cur][visit], solve(i, visit | (1 << i)) + map[cur][i]);
	}
	return dp[cur][visit];
}

int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cin >> map[i][j];

	cout << solve(0, 1) << '\n';

	return 0;
}
