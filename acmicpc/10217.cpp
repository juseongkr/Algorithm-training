#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
#define MAX 101
typedef tuple<int, int, int> ti3;
const int INF = 1e9+7;

int t, n, m, k, x, y, c, d;
int dist[MAX][10001];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		vector<ti3> graph[MAX];

		cin >> n >> m >> k;
		for (int i=0; i<k; ++i) {
			cin >> x >> y >> c >> d;
			graph[x].push_back({y, c, d});
		}

		for (int i=0; i<=n; ++i)
			for (int j=0; j<=m; ++j)
				dist[i][j] = INF;

		priority_queue<ti3, vector<ti3>, greater<ti3>> que;
		que.push({0, 0, 1});
		dist[1][0] = 0;

		while (!que.empty()) {
			auto [cost, time, cur] = que.top();
			que.pop();

			if (dist[cur][cost] < time)
				continue;

			for (int i=0; i<graph[cur].size(); ++i) {
				int next = get<0>(graph[cur][i]);
				int next_cost = get<1>(graph[cur][i]) + cost;
				int next_time = get<2>(graph[cur][i]) + time;

				if (next_cost > m)
					continue;

				if (dist[next][next_cost] > next_time) {
					for (int j=next_cost; j<=m; ++j)
						dist[next][j] = min(dist[next][j], next_time);

					que.push({next_cost, next_time, next});
				}
			}
		}

		int ans = INF;
		for (int i=1; i<=m; ++i)
			ans = min(ans, dist[n][i]);

		if (ans == INF)
			cout << "Poor KCM\n";
		else
			cout << ans << '\n';
	}

	return 0;
}
