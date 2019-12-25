#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001
#define MOD 1000000

int n;
int dp[MAX][2][3];

int solve(int a, int b, int c)
{
	if (a == n)
		return 1;

	if (dp[a][b][c] != -1)
		return dp[a][b][c];

	dp[a][b][c] = solve(a+1, b, 0);
	if (b == 0)
		dp[a][b][c] += solve(a+1, b+1, 0);
	if (c < 2)
		dp[a][b][c] += solve(a+1, b, c+1);

	return dp[a][b][c] %= MOD;
}

int main()
{
	cin >> n;

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0, 0) << '\n';

	return 0;
}
