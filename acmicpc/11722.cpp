#include <iostream>
using namespace std;

int num[1001], dp[1001];

int main()
{
	int n, ans = 0;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &num[i]);
		dp[i] = 1;
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<i; ++j) {
			if (num[i] < num[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}

	printf("%d\n", ans);

	return 0;
}
