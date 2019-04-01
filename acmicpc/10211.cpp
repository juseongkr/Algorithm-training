#include <iostream>
using namespace std;

int num[1001], dp[1001];

int main()
{
	int t, n, max_val;
	
	scanf("%d", &t);
	for (int i=0; i<t; ++i) {
		scanf("%d", &n);
		for (int j=0; j<n; ++j)
			scanf("%d", &num[j]);

		dp[0] = num[0];
		max_val = num[0];
		for (int j=1; j<n; ++j) {
			dp[j] = max(dp[j-1] + num[j], num[j]);
			max_val = max(max_val, dp[j]);
		}

		printf("%d\n", max_val);
	}

	return 0;
}
