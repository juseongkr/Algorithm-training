#include <iostream>
using namespace std;
#define MAX 10001

int w[MAX], dp[MAX];

int main()
{
	int n;

	cin >> n;
	for (int i=1; i<=n; ++i)
		cin >> w[i];

	dp[1] = w[1];
	dp[2] = w[1] + w[2];
	for (int i=3; i<=n; ++i) {
		dp[i] = max(dp[i], dp[i-1]);
		dp[i] = max(dp[i], dp[i-2] + w[i]);
		dp[i] = max(dp[i], dp[i-3] + w[i-1] + w[i]);
	}
	cout << dp[n] << '\n';

	return 0;
}
