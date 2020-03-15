#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001
const int MOD = 1e4+7;

int n;
string s;
int dp[MAX][MAX];

int solve(int x, int y)
{
	if (x > y)
		return 0;

	if (x == y)
		return 1;

	if (~dp[x][y])
		return dp[x][y];

	if (x+1 == y)
		return (s[x] == s[y]) + 2;

	dp[x][y] = solve(x+1, y) + solve(x, y-1) - solve(x+1, y-1);
	if (s[x] == s[y])
		dp[x][y] += solve(x+1, y-1) + 1;

	return dp[x][y] = (dp[x][y] + MOD) % MOD;
}

int main()
{
	cin >> s;
	n = s.length();
	memset(dp, -1, sizeof(dp));
	cout << solve(0, n-1) << '\n';

	return 0;
}
