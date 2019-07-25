#include <iostream>
using namespace std;
#define MAX 1500001

int n;
int t[MAX], p[MAX], dp[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i=1; i<=n; ++i)
		cin >> t[i] >> p[i];

	int ans = 0;
	for (int i=1; i<=n+1; ++i) {
		ans = max(ans, dp[i]);
		if (i + t[i] <= n+1)
			dp[i + t[i]] = max(ans + p[i], dp[i + t[i]]);
	}
	cout << ans << '\n';

	return 0;
}
