#include <iostream>
using namespace std;

#define INF 100001
int coin[101], dp[100001];

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);
	for (int i=1; i<=n; ++i)
		scanf("%d", &coin[i]);

	dp[0] = 0;
	for (int i=1; i<=k; ++i)
		dp[i] = INF;

	for (int i=1; i<=n; ++i)
		for (int j=coin[i]; j<=k; ++j)
			dp[j] = min(dp[j], dp[j-coin[i]] + 1);

	if (dp[k] == INF)
		printf("-1\n");
	else
		printf("%d\n", dp[k]);

	return 0;
}
