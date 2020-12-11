#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>
using namespace std;
#define MAX 101
typedef tuple<int, int, int> tp;
const int INF = 1e9+7;

int k, n, r, s, d, l, t;
vector<tp> graph[MAX];
int dp[MAX][10001];

int solve(int cur, int cost)
{
	if (cur == n)
		return 0;

	if (~dp[cur][cost])
		return dp[cur][cost];

	dp[cur][cost] = INF;
	for (int i=0; i<graph[cur].size(); ++i) {
		auto [len, time, next] = graph[cur][i];

		if (cost - time >= 0)
			dp[cur][cost] = min(dp[cur][cost], solve(next, cost - time) + len);
	}

	return dp[cur][cost];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> k >> n >> r;
	for (int i=0; i<r; ++i) {
		cin >> s >> d >> l >> t;
		graph[s].push_back({l, t, d});
	}

	memset(dp, -1, sizeof(dp));

	int ans = solve(1, k);
	if (ans == INF)
		cout << "-1\n";
	else
		cout << ans << '\n';

	return 0;
}
