#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001
const int INF = 1e9+7;
typedef pair<int, int> pii;

int n, m, a, b, t;
int dist[MAX], parent[MAX];
vector<pii> graph[MAX];

int dijkstra(int a, int b)
{
	fill(dist, dist+MAX, INF);
	priority_queue<pii, vector<pii>, greater<pii>> que;
	que.push({0, 1});
	parent[1] = 1;
	dist[1] = 0;

	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second + cost;

			if ((cur == a && next == b) || (cur == b && next == a))
				continue;

			if (dist[next] > next_cost) {
				if (a == 0 && b == 0)
					parent[next] = cur;
				dist[next] = next_cost;
				que.push({next_cost, next});
			}
		}
	}
	if (dist[n] == INF)
		return -1;
	return dist[n];
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> a >> b >> t;
		graph[a].push_back({b, t});
		graph[b].push_back({a, t});
	}

	fill(parent, parent+MAX, -1);
	int fast = dijkstra(0, 0);

	int ans = 0;
	for (int p=n; p!=parent[p]; p=parent[p]) {
		int ret = dijkstra(p, parent[p]);
		if (ret == -1) {
			cout << "-1\n";
			return 0;
		}
		ans = max(ans, ret - fast);
	}
	cout << ans << '\n';
	
	return 0;
}
