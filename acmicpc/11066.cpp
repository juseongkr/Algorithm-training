#include <iostream>
#include <cstring>
using namespace std;
#define MAX 501
const int INF = 1e9+7;

int num[MAX], dp[MAX][MAX];

int solve(int l, int r)
{
	if (l == r)
		return 0;

	if (dp[l][r] != -1)
		return dp[l][r];

	int sum = 0;
	for (int i=l; i<=r; ++i)
		sum += num[i];

	dp[l][r] = INF;
	for (int i=l; i<=r; ++i)
		dp[l][r] = min(dp[l][r], solve(l, i) + solve(i+1, r) + sum);
	return dp[l][r];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n;

	cin >> t;
	while (t--) {
		cin >> n;
		memset(dp, -1, sizeof(dp));
		for (int i=1; i<=n; ++i)
			cin >> num[i];

		cout << solve(1, n) << '\n';
	}

	return 0;
}
