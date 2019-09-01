#include <iostream>
using namespace std;
#define MAX 1001

int n, m, t, ans;
int dp[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			cin >> t;
			if (t == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = 0;
		}
	}

	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			if (dp[i][j])
				dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << '\n';

	return 0;
}
