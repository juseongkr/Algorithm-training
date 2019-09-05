#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001

int t, n;
int card[MAX];
int dp[2][MAX][MAX];

int solve(int cur, int l, int r)
{
	if (l == r) {
		if (cur == 0)
			return card[l];
		else
			return 0;
	}

	if (dp[cur][l][r] != -1)
		return dp[cur][l][r];

	if (cur == 0)
		dp[cur][l][r] = max(solve(1-cur, l+1, r) + card[l], solve(1-cur, l, r-1) + card[r]);
	else
		dp[cur][l][r] = min(solve(1-cur, l+1, r), solve(1-cur, l, r-1));

	return dp[cur][l][r];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while (t--) {
		cin >> n;
		for (int i=0; i<n; ++i)
			cin >> card[i];

		memset(dp, -1, sizeof(dp));
		cout << solve(0, 0, n-1) << '\n';
	}

	return 0;
}
