#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001

int t, w;
int tree[MAX];
int dp[3][MAX][31];

int solve(int c, int s, int m)
{
	if (s == t)
		return 0;

	if (dp[c][s][m] != -1)
		return dp[c][s][m];

	dp[c][s][m] = 0;
	if (c == tree[s]) {
		if (m + 1 <= w)
			dp[c][s][m] = max(solve(3-c, s+1, m+1), solve(c, s+1, m) + 1);
		else
			dp[c][s][m] = solve(c, s+1, m) + 1;
	} else {
		if (m + 1 <= w)
			dp[c][s][m] = max(solve(3-c, s+1, m+1) + 1, solve(c, s+1, m));
		else
			dp[c][s][m] = solve(c, s+1, m);
	}
	return dp[c][s][m];
}

int main()
{
	cin >> t >> w;
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<t; ++i)
		cin >> tree[i];

	cout << solve(1, 0, 0) << '\n';

	return 0;
}
