#include <iostream>
using namespace std;

int dp[2][100001];
int s[2][100001];

int main()
{
	int t, n;

	scanf("%d", &t);
	for (int i=0; i<t; ++i) {
		scanf("%d", &n);
		for (int i=0; i<2; ++i)
			for (int j=1; j<=n; ++j)
				scanf("%d", &s[i][j]);

		dp[0][0] = dp[1][0] = 0;
		dp[0][1] = s[0][1];
		dp[1][1] = s[1][1];

		for (int i=2; i<=n; ++i) {
			dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + s[0][i];
			dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + s[1][i];
		}
		printf("%d\n", max(dp[0][n], dp[1][n]));
	}

	return 0;
}
