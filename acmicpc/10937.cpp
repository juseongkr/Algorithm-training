#include <iostream>
#include <cstring>
using namespace std;

const int cost[4][4] = {{100, 70, 40, 0},
       			{70, 50, 30, 0},
			{40, 30, 20, 0},
			{0, 0, 0, 0}};

int n, t;
int dubu[12][12];
int dp[12][12][1<<13];
string s;

int score(char c)
{
	if ('A' <= c && c <= 'C')
		return c-'A';
	return 3;
}

int solve(int i, int j, int b)
{
	if (dp[i][j][b] != -1)
		return dp[i][j][b];

	if (i == n)
		return 0;

	if (j == n) {
		dp[i][j][b] = solve(i+1, 0, b);
		return dp[i][j][b];
	}

	if (!(b & (1 << n))) {
		if (j+1 < n && !(b & (1 << (n-1)))) {
			int cur = dubu[i][j];
			int next = dubu[i][j+1];
			int ret = solve(i, j+2, (b << 2) % (1 << (n+1))) + cost[cur][next];
			dp[i][j][b] = max(dp[i][j][b], ret);
		}
		if (i+1 < n && !(b & 1)) {
			int cur = dubu[i][j];
			int next = dubu[i+1][j];
			int ret = solve(i, j+1, ((b | 1) << 1) % (1 << (n+1))) + cost[cur][next];
			dp[i][j][b] = max(dp[i][j][b], ret);
		}
		dp[i][j][b] = max(dp[i][j][b], solve(i, j+1, (b << 1) % (1 << (n+1))));
	}
	dp[i][j][b] = max(dp[i][j][b], solve(i, j+1, (b << 1) % (1 << (n+1))));

	return dp[i][j][b];
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> s;
		for (int j=0; j<n; ++j)
			dubu[i][j] = score(s[j]);
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0, 0) << '\n';

	return 0;
}
