#include <iostream>
#include <cstring>
#include <vector>
#include <tuple>
using namespace std;
#define MAX 101
#define MAXT 10001
const int INF = 1e9+7;
typedef tuple<int, int, int> tp;

int n, t, m, a, b, c, d, l;
vector<tp> graph[MAX];
int dp[MAX][MAXT];

int dfs(int cur, int time)
{
	if (cur == n)
		return 0;

	if (~dp[cur][time])
		return dp[cur][time];

	dp[cur][time] = INF;
	for (int i=0; i<graph[cur].size(); ++i) {
		auto [next, next_time, next_cost] = graph[cur][i];
		if (next_time <= time)
			dp[cur][time] = min(dp[cur][time], dfs(next, time - next_time) + next_cost);
	}

	return dp[cur][time];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> t >> m >> l;
	for (int i=0; i<l; ++i) {
		cin >> a >> b >> c >> d;
		graph[a].push_back({b, c, d});
		graph[b].push_back({a, c, d});
	}

	memset(dp, -1, sizeof(dp));
	int ans = dfs(1, t);

	if (ans <= m)
		cout << ans << '\n';
	else
		cout << "-1\n";

	return 0;
}
