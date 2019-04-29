#include <iostream>
#include <functional>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

#define MAX_VAL 801
typedef pair<int, int> pii;

vector<pii> graph[MAX_VAL];
int dist[MAX_VAL], visit[MAX_VAL];
int N, E, s, e, w, a, b, ans;
bool flag;

int dijkstra(int start, int end)
{
	priority_queue<pii, vector<pii>, greater<pii>> que;
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
	if (dist[end] == INT_MAX) {
		flag = false;
		return INT_MAX;
	} else {
		return dist[end];
	}
}

int main()
{
	scanf("%d %d", &N, &E);
	for (int i=0; i<E; ++i) {
		scanf("%d %d %d", &s, &e, &w);
		graph[s].push_back({e, w});
		graph[e].push_back({s, w});
	}
	scanf("%d %d", &a, &b);

	flag = true;
	int ret1 = dijkstra(1, a) + dijkstra(a, b) + dijkstra(b, N);
	int ret2 = dijkstra(1, b) + dijkstra(b, a) + dijkstra(a, N);

	if (flag)
		printf("%d\n", min(ret1, ret2));
	else
		printf("-1\n");
	
	return 0;
}
