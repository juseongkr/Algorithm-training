#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	pair<int, int> li[101];
	int dp[101];
	int n, len = 0;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d %d", &li[i].first, &li[i].second);
		dp[i] = 1;
	}

	sort(li, li + n);

	for (int i=0; i<n; ++i) {
		for (int j=0; j<i; ++j) {
			if (li[i].second > li[j].second)
				dp[i] = max(dp[i], dp[j] + 1);
		}
		len = max(len, dp[i]);
	}

	printf("%d\n", n - len);

	return 0;
}
