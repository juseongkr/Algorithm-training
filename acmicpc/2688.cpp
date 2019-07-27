#include <iostream>
#include <cstring>
using namespace std;
#define MAX 65

int t, n;
long long dp[10][MAX];

long long solve(int cur, int len)
{
	if (cur < 10 && len == 1)
		return 1;

	if (dp[cur][len] != -1)
		return dp[cur][len];

	dp[cur][len] = 0;
	for (int i=cur; i<=9; ++i)
		dp[cur][len] += solve(i, len-1);

	return dp[cur][len];
}

int main()
{
	cin >> t;
	while (t--) {
		cin >> n;

		memset(dp, -1, sizeof(dp));
		long long ans = 0;
		for (int i=0; i<10; ++i)
			ans += solve(i, n);

		cout << ans << '\n';
	}

	return 0;
}
