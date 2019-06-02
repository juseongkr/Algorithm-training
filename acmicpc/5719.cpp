#include <iostream>
#include <functional>
#include <climits>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define MAX 501
typedef pair<int, int> pii;

vector<pair<int, int>> graph[MAX], rev[MAX];
int removed[MAX][MAX], dist[MAX];
int n, m, a, b, c, start, dest;

void dijkstra()
{
	priority_queue<pii, vector<pii>, greater<pii>> que;

	fill(dist, dist+MAX, INT_MAX);
	que.push({0, start});
	dist[start] = 0;
	while (!que.empty()) {
		int cost = que.top().first;
		int cur = que.top().second;
		que.pop();

		if (cost > dist[cur])
			continue;

		for (int i=0; i<graph[cur].size(); ++i) {
			int next_cur = graph[cur][i].first;
			int next_cost = graph[cur][i].second;

			if (removed[cur][next_cur])
				continue;

			if (next_cost + cost < dist[next_cur]) {
				que.push({next_cost + cost, next_cur});
				dist[next_cur] = next_cost + cost;
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

		if (cur == start)
			continue;

		for (int i=0; i<rev[cur].size(); ++i) {
			int prev = rev[cur][i].first;
			int cost = rev[cur][i].second;

			if (dist[prev] + cost == dist[cur]) {
				removed[prev][cur] = 1;
				que.push(prev);
			}
		}
	}
}

int main()
{
	while (cin >> n >> m && n != 0 && m != 0) {
		cin >> start >> dest;

		memset(removed, 0, sizeof(removed));
		for (int i=0; i<m; ++i) {
			cin >> a >> b >> c;
			graph[a].push_back({b, c});
			rev[b].push_back({a, c});
		}

		dijkstra();
		bfs();
		dijkstra();

		if (dist[dest] == INT_MAX)
			cout << "-1\n";
		else
			cout << dist[dest] << '\n';

		for (int i=0; i<MAX; ++i) {
			graph[i].clear();
			rev[i].clear();
		}
	}

	return 0;
}
