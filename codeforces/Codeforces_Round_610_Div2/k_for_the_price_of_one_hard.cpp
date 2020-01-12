#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 200002
const int INF = 1e9+7;

int t, n, p, k;
int num[MAX], dp[MAX];

int solve(int cur)
{
	if (cur == 0)
		return 0;

	if (dp[cur] != -1)
		return dp[cur];

	dp[cur] = min(INF, solve(cur-1) + num[cur]);
	if (cur >= k)
		dp[cur] = min(dp[cur], solve(cur-k) + num[cur]);

	return dp[cur];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> p >> k;
		fill(dp+1, dp+MAX, -1);
		for (int i=1; i<=n; ++i)
			cin >> num[i];

		sort(num+1, num+n+1);

		int ans = 0;
		for (int i=1; i<=n; ++i)
			if (solve(i) <= p)
				ans = i;

		cout << ans << '\n';
	}

	return 0;
}
