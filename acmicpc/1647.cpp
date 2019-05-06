#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100001
typedef pair<int, int> pii;
int visit[MAX];

int main()
{
	priority_queue<pii, vector<pii>, greater<pii>> que;
	vector<pii> graph[MAX];
	int n, m, a, b, c, total = 0, max_val = 0;
	
	scanf("%d %d", &n, &m);
	for (int i=0; i<m; ++i) {
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

		max_val = max(max_val, cost);
		visit[cur] = 1;
		total += cost;

		for (int i=0; i<graph[cur].size(); ++i) {
			int next_cur = graph[cur][i].first;
			int next_cost = graph[cur][i].second;
			que.push({next_cost, next_cur});
		}
	}
	printf("%d\n", total - max_val);

	return 0;
}
