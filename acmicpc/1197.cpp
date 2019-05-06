#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

#define MAX_VAL 100001
typedef pair<int, int> pii;
int visit[MAX_VAL];

int main()
{
	priority_queue<pii, vector<pii>, greater<pii>> que;
	vector<pii> graph[MAX_VAL];
	int v, e, a, b, c, total = 0;

	scanf("%d %d", &v, &e);
	for (int i=0; i<e; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	que.push({0, 1});
	while (!que.empty()) {
		int cost = que.top().first;
		int cur = que.top().second;
		que.pop();

		if (visit[cur])
			continue;

		visit[cur] = 1;
		total += cost;

		for (int i=0; i<graph[cur].size(); ++i) {
			int next_cur = graph[cur][i].first;
			int next_cost = graph[cur][i].second;
			que.push({next_cost, next_cur});
		}
	}
	printf("%d\n", total);

	return 0;
}
