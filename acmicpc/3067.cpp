#include <iostream>
#include <cstring>
using namespace std;
#define MAX 10001

int t, n, m;
int coin[MAX], dp[MAX];

int main()
{
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=1; i<=n; ++i)
			cin >> coin[i];
		cin >> m;

		fill(dp, dp+MAX, 0);
		dp[0] = 1;
		for (int i=1; i<=n; ++i)
			for (int j=coin[i]; j<=m; ++j)
				dp[j] += dp[j-coin[i]];

		cout << dp[m] << '\n';
	}

	return 0;
}
