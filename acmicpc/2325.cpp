#include <iostream>
#include <functional>
#include <climits>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001
typedef pair<int, int> pii;

vector<pair<int, int>> graph[MAX];
int dist[MAX], pre[MAX], pre2[MAX];
int n, m, a, b, c, ans;
const int start = 1;

void dijkstra(int u, int v)
{
	priority_queue<pii, vector<pii>, greater<pii>> que;
	fill(dist, dist+MAX, INT_MAX);
	fill(pre, pre+MAX, -1);
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

			if ((cur == u && next_cur == v) || (cur == v && next_cur == u))
				continue;

			if (next_cost + cost < dist[next_cur]) {
				que.push({next_cost + cost, next_cur});
				dist[next_cur] = next_cost + cost;
				pre[next_cur] = cur;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	dijkstra(0, 0);

	for (int i=0; i<MAX; ++i)
		pre2[i] = pre[i];

	for (int i=n; pre[i]!=-1; i=pre2[i]) {
		dijkstra(i, pre2[i]);
		ans = max(ans, dist[n]);
	}

	cout << ans << '\n';

	return 0;
}
