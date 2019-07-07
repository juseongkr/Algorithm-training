#include <iostream>
using namespace std;
#define MAX 41

int dp[MAX];

int main()
{
	int n, m, t;

	cin >> n >> m;
	dp[0] = dp[1] = 1;
	for (int i=2; i<=n; ++i)
		dp[i] = dp[i-1] + dp[i-2];

	int ans = 1, prev = 0;
	for (int i=0; i<m; ++i) {
		cin >> t;
		ans *= dp[t-prev-1];
		prev = t;
	}
	ans *= dp[n-prev];

	cout << ans << '\n';

	return 0;
}
