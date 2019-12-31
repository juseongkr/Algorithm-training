#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101
const int MOD = 1e9+7;

int n, ans;
int dp[MAX][10][4][4];

int solve(int cur, int val, int a, int b)
{
	if (val < 0 || val > 9 || a >= 3 || b >= 3)
		return 0;
	if (cur == 1)
		return 1;

	if (dp[cur][val][a][b] != -1)
		return dp[cur][val][a][b];
	
	dp[cur][val][a][b] = (solve(cur-1, val+1, a+1, 0) + solve(cur-1, val-1, 0, b+1)) % MOD;

	return dp[cur][val][a][b];
}

int main()
{
	cin >> n;

	memset(dp, -1, sizeof(dp));
	for (int i=0; i<10; ++i)
		ans = (ans + solve(n, i, 0, 0)) % MOD;
	cout << ans << '\n';

	return 0;
}
