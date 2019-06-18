#include <iostream>
#include <climits>
using namespace std;
#define MAX 501

int dp[MAX][MAX];

int main()
{
	int n, k;

	cin >> k >> n;
	for (int i=1; i<=n; ++i)
		dp[i][1] = 1;

	for (int i=1; i<=k; ++i)
		dp[1][i] = i;

	for (int i=2; i<=n; ++i) {
		for (int j=2; j<=k; ++j) {
			dp[i][j] = INT_MAX;
			for (int p=1; p<=j; ++p) {
				int ret = max(dp[i-1][p-1], dp[i][j-p]) + 1;
				dp[i][j] = min(dp[i][j], ret);
			}
		}
	}
	cout << dp[n][k] << '\n';

	return 0;
}
