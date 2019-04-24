#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int num[501], sum[501];
int dp[501][501];

int solve(int left, int right)
{
	if (left >= right)
		return 0;

	if (left + 1 == right)
		return num[left] + num[right];

	if (dp[left][right] != 0)
		return dp[left][right];

	dp[left][right] = INT_MAX;
	for (int mid=left; mid<=right; ++mid) {
		int next = solve(left, mid) + solve(mid+1, right) + sum[right] - sum[left-1];
		dp[left][right] = min(dp[left][right], next);
	}

	return dp[left][right];
}

int main()
{
	int t, n;

	scanf("%d", &t);
	while (t--) {
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);
		for (int i=1; i<=n; ++i) {
			scanf("%d", &num[i]);
			sum[i] = sum[i-1] + num[i];
		}

		printf("%d\n", solve(1, n));
	}

	return 0;
}
