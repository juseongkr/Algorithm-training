#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define MAX_VAL 1001
typedef pair<int, int> pii;

priority_queue<pii, vector<pii>, greater<pii>> que;
vector<pii> graph[MAX_VAL];
int dist[MAX_VAL], visit[MAX_VAL];
int n, m, x, a, b, w, ans;

int dijkstra(int start, int end)
{
	fill(dist, dist+MAX_VAL, INT_MAX);
	fill(visit, visit+MAX_VAL, 0);

	dist[start] = 0;
	que.push({0, start});
	while (!que.empty()) {
		int cost = que.top().first;
		int cur = que.top().second;
		que.pop();

		if (cost >= dist[cur] && visit[cur])
			continue;

		visit[cur] = 1;
		for (int i=0; i<graph[cur].size(); ++i) {
			int next_cur = graph[cur][i].first;
			int next_cost = graph[cur][i].second;

			if (next_cost + cost < dist[next_cur]) {
				que.push({next_cost + cost, next_cur});
				dist[next_cur] = next_cost + cost;
			}
		}
	}
	return dist[end];
}

int main()
{
	scanf("%d %d %d", &n, &m, &x);
	for (int i=0; i<m; ++i) {
		scanf("%d %d %d", &a, &b, &w);
		graph[a].push_back({b, w});
	}

	for (int i=1; i<=n; ++i) {
		if (i == x)
			continue;
		ans = max(ans, dijkstra(i, x) + dijkstra(x, i));
	}

	printf("%d\n", ans);

	return 0;
}
