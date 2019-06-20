#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1001

int a[MAX], b[MAX];
int dp[MAX][MAX];

int main()
{
	int n, m;

	cin >> n >> m;
	for (int i=1; i<=n; ++i)
		cin >> a[i];
	for (int i=1; i<=m; ++i)
		cin >> b[i];

	sort(a+1, a+n+1);
	sort(b+1, b+m+1);

	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			dp[i][j] = dp[i-1][j-1] + abs(a[i] - b[j]);
			if (i > j)
				dp[i][j] = min(dp[i][j], dp[i-1][j]);
			if (i < j)
				dp[i][j] = min(dp[i][j], dp[i][j-1]);
		}
	}
	cout << dp[n][m] << '\n';

	return 0;
}
