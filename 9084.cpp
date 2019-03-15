#include <iostream>
#include <string.h>
using namespace std;

int dp[10001], coin[10001];

int main()
{
	int num, n, m;

	scanf("%d", &num);

	for (int k=0; k<num; ++k) {
		scanf("%d", &n);

		memset(dp, 0, sizeof(dp));
		dp[0] = 1;

		for (int i=1; i<=n; ++i)
			scanf("%d", &coin[i]);

		scanf("%d", &m);

		for (int i=1; i<=n; ++i)
			for (int j=coin[i]; j<=m; ++j)
				dp[j] += dp[j - coin[i]];

		cout << dp[m] << '\n';
	}

	return 0;
}
