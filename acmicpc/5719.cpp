#include <iostream>
#include <functional>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define MAX 501
typedef pair<int, int> pii;
const int INF = 1e9+7;

vector<pair<int, int>> graph[MAX], rev[MAX];
int n, m, a, b, c, start, dest;
bool visit[MAX][MAX];
int dist[MAX];

void dijkstra()
{
	fill(dist, dist+n, INF);
	priority_queue<pii, vector<pii>, greater<pii>> que;
	que.push({0, start});
	dist[start] = 0;

	while (!que.empty()) {
		int cost = que.top().first;
		int cur = que.top().second;
		que.pop();

		if (cost > dist[cur])
			continue;

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second + cost;

			if (graph[cur][i].second == -1)
				continue;

			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				que.push({next_cost, next});
				rev[next].clear();
				rev[next].push_back({cur, next_cost});
			} else if (dist[next] == next_cost) {
				rev[next].push_back({cur, next_cost});
			}
		}
	}
}

void bfs()
{
	queue<int> que;
	que.push(dest);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i=0; i<rev[cur].size(); ++i) {
			int next = rev[cur][i].first;
			if (visit[cur][next])
				continue;
			visit[cur][next] = 1;

			for (auto &g : graph[next])
				if (g.first == cur)
					g.second = -1;

			que.push(next);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	while (1) {
		cin >> n >> m;
		if (n == 0)
			break;
		cin >> start >> dest;

		for (int i=0; i<m; ++i) {
			cin >> a >> b >> c;
			graph[a].push_back({b, c});
		}

		dijkstra();
		bfs();
		dijkstra();

		if (dist[dest] == INF)
			cout << "-1\n";
		else
			cout << dist[dest] << '\n';

		memset(visit, 0, sizeof(visit));
		for (int i=0; i<n; ++i) {
			graph[i].clear();
			rev[i].clear();
		}
	}

	return 0;
}
