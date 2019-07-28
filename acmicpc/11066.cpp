#include <iostream>
#include <cstring>
using namespace std;
#define MAX 501

int num[MAX];
int dp[MAX][MAX];

int solve(int l, int r)
{
	if (l == r)
		return 0;

	if (dp[l][r] != -1)
		return dp[l][r];

	int sum = 0;
	for (int i=l; i<=r; ++i)
		sum += num[i];

	dp[l][r] = 1e9+7;
	for (int i=l; i<=r; ++i)
		dp[l][r] = min(dp[l][r], solve(l, i) + solve(i+1, r) + sum);
	return dp[l][r];
}

int main()
{
	int t, n;

	cin >> t;
	while (t--) {
		memset(dp, -1, sizeof(dp));
		cin >> n;
		for (int i=1; i<=n; ++i)
			cin >> num[i];

		cout << solve(1, n) << '\n';
	}

	return 0;
}
