#include <iostream>
#include <functional>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

#define MAX_VAL 1001
typedef pair<int, int> pii;

int main()
{
	priority_queue<pii, vector<pii>, greater<pii>> que;
	vector<pii> graph[MAX_VAL];
	int dist[MAX_VAL], visit[MAX_VAL];
	int n, m, s, e, w, start, end;

	scanf("%d %d", &n, &m);
	fill(dist, dist+MAX_VAL, INT_MAX);
	fill(visit, visit+MAX_VAL, 0);
	for (int i=0; i<m; ++i) {
		scanf("%d %d %d", &s, &e, &w);
		graph[s].push_back({e, w});
	}
	scanf("%d %d", &start, &end);

	dist[start] = 0;
	que.push({0, start});
	while (!que.empty()) {
		int cost = que.top().first;
		int cur = que.top().second;
		que.pop();

		if (dist[cur] <= cost && visit[cur])
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

	printf("%d\n", dist[end]);

	return 0;
}
