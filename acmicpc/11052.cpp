#include <iostream>
using namespace std;

int card[1001], dp[1001];

int main()
{
	int n;

	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
		scanf("%d", &card[i]);

	for (int i=1; i<=n; ++i)
		for (int j=1; j<=i; ++j)
			dp[i] = max(dp[i], dp[i-j] + card[j]);

	printf("%d\n", dp[n]);

	return 0;
}
