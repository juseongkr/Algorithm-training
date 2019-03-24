#include <iostream>
using namespace std;

#define INF 1000001
#define MAX_NUM 320
int num[MAX_NUM], dp[100001];

int main()
{
	int n;

	scanf("%d", &n);
	for (int i=1; i<=MAX_NUM; ++i)
		num[i] = i * i;

	dp[0] = 0;
	for (int i=1; i<=n; ++i)
		dp[i] = INF;

	for (int i=1; i<=MAX_NUM; ++i)
		for (int j=num[i]; j<=n; ++j)
			dp[j] = min(dp[j], dp[j-num[i]] + 1);

	printf("%d\n", dp[n]);

	return 0;
}
