#include <iostream>
using namespace std;

int num[1001], dp[1001];

int main()
{
	int n, ans = 0;

	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d", &num[i]);

	for (int i=0; i<n; ++i) {
		dp[i] = num[i];
		for (int j=0; j<i; ++j) {
			if (num[i] > num[j])
				dp[i] = max(dp[i], dp[j] + num[i]);
		}
		ans = max(ans, dp[i]);
	}

	printf("%d\n", ans);

	return 0;
}
