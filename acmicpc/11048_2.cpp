#include <iostream>
using namespace std;
#define MAX 1001

int dp[MAX][MAX], map[MAX][MAX];

int main()
{
	int n, m;

	cin >> n >> m;
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=m; ++j)
			cin >> map[i][j];

	for (int i=1; i<=n; ++i)
		for (int j=1; j<=m; ++j)
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + map[i][j];

	cout << dp[n][m] << '\n';

	return 0;
}
