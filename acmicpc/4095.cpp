#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001

int map[MAX][MAX], dp[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;

	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		memset(dp, 0, sizeof(dp));
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=m; ++j)
				cin >> map[i][j];

		int ans = 0;
		for (int i=1; i<=n; ++i) {
			for (int j=1; j<=m; ++j) {
				dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
				dp[i][j] *= map[i][j];
				ans = max(ans, dp[i][j]);
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
