#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1000001
const int MOD = 1e9;

int n;
int dp[MAX][21];

int solve(int num, int bit)
{
	if (num < 0)
		return 0;

	if (num == 0)
		return 1;

	if (num > 0 && bit == 0)
		return 1;

	if (dp[num][bit] != -1)
		return dp[num][bit];

	dp[num][bit] = solve(num, bit-1) % MOD + solve(num - (1 << bit), bit) % MOD;
	return dp[num][bit] % MOD;
}

int main()
{
	cin >> n;

	memset(dp, -1, sizeof(dp));
	cout << solve(n, 20) << '\n';

	return 0;
}
