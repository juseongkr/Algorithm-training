#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001
const int MOD = 1e9+3;

int n, k;
int dp[MAX][MAX];

int solve(int cur, int cnt)
{
	if (cnt > cur/2)
		return 0;
	if (cnt == 1)
		return cur;

	if (~dp[cur][cnt])
		return dp[cur][cnt];

	dp[cur][cnt] = solve(cur-2, cnt-1) + solve(cur-1, cnt);

	return dp[cur][cnt] %= MOD;
}

int main()
{
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	cout << solve(n, k) << '\n';

	return 0;
}
