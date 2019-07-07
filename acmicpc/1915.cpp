#include <iostream>
using namespace std;
#define MAX 1001

int dp[MAX][MAX];

int main()
{
	int n, m, ans = 0;
	char c;

	cin >> n >> m;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			cin >> c;
			dp[i][j] = c-'0';
		}
	}

	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			if (dp[i][j])
				dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans * ans << '\n';

	return 0;
}
