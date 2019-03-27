#include <iostream>
using namespace std;

int main()
{
	int arr[100001] = {0, };
	int dp[100001] = {0, };
	int n, max_val = -99999;

	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d", &arr[i]);
	
	dp[0] = arr[0];
	for (int i=1; i<n; ++i)
		dp[i] = max(dp[i-1] + arr[i], arr[i]);

	for (int i=0; i<n; ++i)
		max_val = max(max_val, dp[i]);

	printf("%d\n", max_val);

	return 0;
}
