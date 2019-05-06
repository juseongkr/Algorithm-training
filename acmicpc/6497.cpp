#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

#define MAX 200001
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> que;
vector<pii> graph[MAX];
int visit[MAX];

int main()
{
	int m, n;
	while (1) {
		int a, b, c, sum = 0, total = 0;

		scanf("%d %d", &m, &n);
		if (m == 0 && n == 0)
			break;

		for (int i=0; i<n; ++i) {
			graph[i].clear();
			visit[i] = 0;
		}

		for (int i=0; i<n; ++i) {
			scanf("%d %d %d", &a, &b, &c);
			graph[a].push_back({b, c});
			graph[b].push_back({a, c});
			sum += c;
		}

		que.push({0, 0});

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
		printf("%d\n", sum - total);
	}

	return 0;
}
