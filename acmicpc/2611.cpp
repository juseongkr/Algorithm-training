#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 1001

int n, m, x, y, k;
vector<pair<int, int>> graph[MAX];
int dp[MAX], path[MAX];

int solve(int cur)
{
	if (~dp[cur])
		return dp[cur];

	dp[cur] = 0;
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i].first;
		int cost = graph[cur][i].second;
		int next_cost = solve(next) + cost;

		if (dp[cur] < next_cost) {
			dp[cur] = next_cost;
			path[cur] = next;
		}
	}

	return dp[cur];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> k;
		if (y == 1)
			graph[x].push_back({n+1, k});
		else
			graph[x].push_back({y, k});
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(1) << '\n';

	int idx = 1;
	while (idx <= n) {
		cout << idx << " ";
		idx = path[idx];
	}
	cout << "1\n";

	return 0;
}
