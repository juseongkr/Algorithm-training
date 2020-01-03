#include <iostream>
#include <cstring>
using namespace std;
#define MAX 10001
#define MOD 987654321

int n;
long long dp[MAX];

long long solve(int cur)
{
	if (cur == 0)
		return 1;
	if (cur == 1)
		return 0;

	if (dp[cur] != -1)
		return dp[cur];

	dp[cur] = 0;
	for (int i=2; i<=cur; ++i)
		dp[cur] = (dp[cur] + solve(i-2) * solve(cur-i)) % MOD;

	return dp[cur];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;

	memset(dp, -1, sizeof(dp));
	cout << solve(n) << '\n';

	return 0;
}
