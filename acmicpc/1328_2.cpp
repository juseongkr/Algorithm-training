#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101
#define MOD 1000000007

int n, l, r;
long long dp[MAX][MAX][MAX];

long long solve(int c, int l, int r)
{
	if (c == 0 || l == 0 || r == 0)
		return 0;

	if ((l == 1 && c == r) && (r == 1 && c == l))
		return 1;

	if (dp[c][l][r] != -1)
		return dp[c][l][r];

	dp[c][l][r] = (solve(c-1, l, r) * (c-2) + solve(c-1, l-1, r) + solve(c-1, l, r-1)) % MOD;

	return dp[c][l][r];
}

int main()
{
	cin >> n >> l >> r;
	memset(dp, -1, sizeof(dp));

	cout << solve(n, l, r) << '\n';

	return 0;
}
