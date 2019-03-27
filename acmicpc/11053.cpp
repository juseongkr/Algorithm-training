#include <iostream>
using namespace std;

int main()
{
	int arr[1001];
	int dp[1001] = {0, };
	int n, max_val = 0;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &arr[i]);
		dp[i] = 1;
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<i; ++j) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j]+1);
		}
		max_val = max(max_val, dp[i]);
	}

	printf("%d\n", max_val);
	
	return 0;
}
