#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9+7;

int T, n;
int dp[3], cost[3];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	while (1) {
		cin >> n;
		if (n == 0)
			break;

		for (int i=0; i<3; ++i)
			cin >> dp[i];

		dp[0] = INF;
		dp[2] += dp[1];
		for (int i=1; i<n; ++i) {
			cin >> cost[0] >> cost[1] >> cost[2];
			cost[0] += min(dp[0], dp[1]);
			cost[1] += min({dp[0], cost[0], dp[1], dp[2]});
			cost[2] += min({cost[1], dp[1], dp[2]});

			dp[0] = cost[0];
			dp[1] = cost[1];
			dp[2] = cost[2];
		}
		cout << ++T << ". " << dp[1] << '\n';
	}

	return 0;
}
