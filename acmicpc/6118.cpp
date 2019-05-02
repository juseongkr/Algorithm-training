#include <iostream>
#include <functional>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

#define MAX_VAL 20001
typedef pair<int, int> pii;

int main()
{
	priority_queue<pii, vector<pii>, greater<pii>> que;
	vector<int> graph[MAX_VAL];
	int dist[MAX_VAL], visit[MAX_VAL];
	int n, m, a, b, max_val = 0, cnt = 0;

	scanf("%d %d", &n, &m);
	fill(dist, dist+n+1, INT_MAX);
	fill(visit, visit+n+1, 0);
	for (int i=0; i<m; ++i) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dist[1] = 0;
	que.push({0, 1});
	while (!que.empty()) {
		int cost = que.top().first;
		int cur = que.top().second;
		que.pop();

		if (dist[cur] <= cost && visit[cur])
			continue;

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];

			if (cost + 1 < dist[next]) {
				que.push({cost+1, next});
				dist[next] = cost+1;
			}
		}
	}

	for (int i=1; i<=n; ++i)
		max_val = max(max_val, dist[i]);
	
	for (int i=1; i<=n; ++i) {
		if (max_val == dist[i]) {
			printf("%d ", i);
			break;
		}
	}

	printf("%d ", max_val);

	for (int i=1; i<=n; ++i)
		if (dist[i] == max_val)
			cnt++;

	printf("%d\n", cnt);

	return 0;
}
