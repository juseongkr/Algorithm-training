#include <iostream>
#include <cstring>
using namespace std;
#define MAX 201
#define MOD 1000000000

int n, k;
int dp[MAX][MAX];

int solve(int cnt, int sum)
{
	if (sum > n)
		return 0;
	if (cnt == k && sum == n)
		return 1;
	if (cnt == k && sum != n)
		return 0;

	if (dp[cnt][sum] != -1)
		return dp[cnt][sum];

	dp[cnt][sum] = 0;
	for (int i=0; i<=n; ++i)
		dp[cnt][sum] = (dp[cnt][sum] + solve(cnt+1, sum+i)) % MOD;

	return dp[cnt][sum];
}

int main()
{
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';

	return 0;
}
