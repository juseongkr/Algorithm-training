#include <iostream>
#include <functional>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 1001
#define FUEL 101
typedef tuple<int, int, int> tp;
const int INF = 1e9+7;

int n, m, x, y, z, q;
vector<pair<int, int>> graph[MAX];
int pri[MAX], dist[MAX][FUEL];
bool visit[MAX][FUEL];

int dijkstra(int f, int s, int e)
{
	memset(visit, 0, sizeof(visit));
	for (int i=0; i<n; ++i)
		fill(dist[i], dist[i]+FUEL, INF);

	priority_queue<tp, vector<tp>, greater<tp>> que;
	que.push({0, s, 0});
	dist[s][0] = 0;

	while (!que.empty()) {
		auto [cost, cur, fuel] = que.top();
		que.pop();

		if (visit[cur][fuel])
			continue;
		visit[cur][fuel] = 1;

		if (cur == e)
			return cost;

		if (fuel < f && dist[cur][fuel+1] > pri[cur] + cost) {
			dist[cur][fuel+1] = pri[cur] + cost;
			que.push({dist[cur][fuel+1], cur, fuel+1});
		}

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second;

			if (fuel >= next_cost && dist[next][fuel-next_cost] > dist[cur][fuel]) {
				dist[next][fuel-next_cost] = dist[cur][fuel];
				que.push({dist[next][fuel-next_cost], next, fuel-next_cost});
			}
		}
	}

	return dist[e][0];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> pri[i];

	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}

	cin >> q;
	while (q--) {
		cin >> z >> x >> y;
		int ans = dijkstra(z, x, y);
		if (ans == INF)
			cout << "impossible\n";
		else
			cout << ans << '\n';
	}

	return 0;
}
