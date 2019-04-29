#include <iostream>
#include <functional>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

#define MAX_LAN 20001
typedef pair<int, int> pii;

int main()
{
	priority_queue<pii, vector<pii>, greater<pii>> que;
	vector<pii> graph[MAX_LAN];
	int dist[MAX_LAN], visit[MAX_LAN];
	int V, E, K, w, s, e;

	scanf("%d %d %d", &V, &E, &K);
	fill(dist, dist+MAX_LAN, INT_MAX);
	fill(visit, visit+MAX_LAN, 0);
	for (int i=0; i<E; ++i) {
		scanf("%d %d %d", &s, &e, &w);
		graph[s].push_back({w, e});
	}

	dist[K] = 0;
	que.push({0, K});
	while (!que.empty()) {
		int cost = que.top().first;
		int cur = que.top().second;
		que.pop();

		if (cost >= dist[cur] && visit[cur])
			continue;

		visit[cur] = 1;
		for (int i=0; i<graph[cur].size(); ++i) {
			int next_cost = graph[cur][i].first;
			int next_cur = graph[cur][i].second;

			if (next_cost + cost < dist[next_cur]) {
				que.push({next_cost + cost, next_cur});
				dist[next_cur] = next_cost + cost;
			}
		}
	}

	for (int i=1; i<=V; ++i) {
		if (dist[i] == INT_MAX)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}

	return 0;
}
