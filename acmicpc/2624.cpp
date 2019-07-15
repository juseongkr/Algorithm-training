#include <iostream>
#include <cstring>
using namespace std;
#define MAX_T 10001
#define MAX_K 101

int t, k;
int coin[MAX_K], cnt[MAX_K];
int dp[MAX_K][MAX_T];

int solve(int cur, int cash)
{
	if (cash == 0)
		return 1;
	if (cur == k)
		return 0;

	if (dp[cur][cash] != -1)
		return dp[cur][cash];

	dp[cur][cash] = 0;
	for (int i=0; i<=cnt[cur]; ++i)
		if (cash - (coin[cur] * i) >= 0)
			dp[cur][cash] += solve(cur+1, cash - (coin[cur] * i));

	return dp[cur][cash];
}

int main()
{
	cin >> t >> k;
	for (int i=0; i<k; ++i)
		cin >> coin[i] >> cnt[i];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, t) << '\n';

	return 0;
}
