#include <iostream>
#include <cstring>
using namespace std;
#define MAX 202

int n;
int num[MAX], dp[MAX][MAX];

int solve(int l, int r)
{
	if (~dp[l][r])
		return dp[l][r];

	dp[l][r] = 0;
	for (int i=l+1; i<r; ++i)
		dp[l][r] = max(dp[l][r], solve(l, i) + solve(i, r) + num[l] + num[i] + num[r]);

	return dp[l][r];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	while (1) {
		cin >> n;
		if (n == 0)
			break;

		memset(dp, -1, sizeof(dp));
		num[0] = num[n+1] = 0;
		for (int i=1; i<=n; ++i)
			cin >> num[i];

		int ans = 0;
		for (int i=1; i<n; ++i)
			for (int j=i+1; j<=n; ++j)
				ans = max(ans, solve(0, i) + solve(i, j) + solve(j, n+1));

		cout << ans << '\n';
	}

	return 0;
}
