#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101

int n, k;
int dp[MAX][MAX][2];

int solve(int cur, int adj, int b)
{
	if (cur == n)
		return 0;

	if (cur == n-1 && adj == k)
		return 1;

	if (dp[cur][adj][b] != -1)
		return dp[cur][adj][b];

	dp[cur][adj][b] = solve(cur+1, adj, 0) + solve(cur+1, adj + b * 1, 1);

	return dp[cur][adj][b];
}

int main()
{
	int t;

	cin >> t;
	while (t--) {
		cin >> n >> k;

		memset(dp, -1, sizeof(dp));
		cout << solve(0, 0, 0) + solve(0, 0, 1) << '\n';
	}

	return 0;
}
