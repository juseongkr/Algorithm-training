#include <iostream>
using namespace std;
#define MAX 21

long long dp[MAX][MAX][MAX];

int main()
{
	int t, n, l, r;

	dp[1][1][1] = 1;
	for (int i=2; i<MAX; ++i)
		for (int j=1; j<MAX; ++j)
			for (int k=1; k<MAX; ++k)
				dp[i][j][k] = dp[i-1][j][k] * (i-2) + dp[i-1][j-1][k] + dp[i-1][j][k-1];
	cin >> t;
	while (t--) {
		cin >> n >> l >> r;

		cout << dp[n][l][r] << '\n';
	}

	return 0;
}
