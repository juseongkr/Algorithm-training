#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101
#define MOD 1000000000

int n, ans;
int dp[MAX][10];

int solve(int cur, int val)
{
	if (val < 0 || val > 9)
		return 0;
	if (cur == 1)
		return 1;

	if (dp[cur][val] != -1)
		return dp[cur][val];

	dp[cur][val] = (solve(cur-1, val+1) + solve(cur-1, val-1)) % MOD;

	return dp[cur][val];
}

int main()
{
	cin >> n;

	memset(dp, -1, sizeof(dp));
	for (int i=1; i<10; ++i)
		ans = (ans + solve(n, i)) % MOD;

	cout << ans << '\n';

	return 0;
}
