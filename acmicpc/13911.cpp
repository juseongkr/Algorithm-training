#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10001
const int INF = 1e9+7;
typedef pair<int, int> pi;

int v, e, a, b, c, m, s, x, y, k;
bool visit[MAX];
vector<pi> graph[MAX];
priority_queue<pi, vector<pi>, greater<pi>> que;

void dijkstra(vector<int> &dist)
{
	fill(visit, visit+MAX, 0);

	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		if (visit[cur])
			continue;
		visit[cur] = 1;

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second + cost;

			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				que.push({next_cost, next});
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> v >> e;
	for (int i=0; i<e; ++i) {
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	vector<int> mac(v+1, INF);
	vector<int> star(v+1, INF);

	cin >> m >> x;
	for (int i=0; i<m; ++i) {
		cin >> k;
		mac[k] = 0;
		que.push({0, k});
	}

	dijkstra(mac);

	cin >> s >> y;
	for (int i=0; i<s; ++i) {
		cin >> k;
		star[k] = 0;
		que.push({0, k});
	}

	dijkstra(star);

	int ans = INF;
	for (int i=1; i<=v; ++i)
		if (mac[i] > 0 && star[i] > 0 && mac[i] <= x && star[i] <= y)
			ans = min(ans, mac[i] + star[i]);

	if (ans == INF)
		cout << "-1\n";
	else
		cout << ans << '\n';

	return 0;
}
