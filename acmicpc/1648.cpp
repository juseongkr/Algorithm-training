#include <iostream>
#include <cstring>
using namespace std;
#define MAX 15
#define MOD 9901

int n, m;
int dp[MAX*MAX][1<<MAX];

int solve(int cur, int bit)
{
	if (cur == n*m && bit == 0)
		return 1;

	if (cur >= n*m)
		return 0;

	if (dp[cur][bit] != -1)
		return dp[cur][bit];

	dp[cur][bit] = 0;
	if (bit & 1) {
		dp[cur][bit] = solve(cur+1, (bit >> 1));
	} else {
		dp[cur][bit] = solve(cur+1, (bit >> 1) | (1 << (m-1)));
		if ((cur % m) != (m-1) && (bit & 2) == 0)
			dp[cur][bit] += solve(cur+2, (bit >> 2));
	}

	dp[cur][bit] %= MOD;

	return dp[cur][bit];
}

int main()
{
	cin >> n >> m;

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';

	return 0;
}
