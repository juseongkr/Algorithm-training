#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001
const int INF = 2*1e9+1;
typedef pair<int, int> pii;

int n, m, s, e1, e2, x, y, z;
vector<pii> graph[MAX];
bool visit[MAX];
int dist[MAX];

int dijkstra(int src, int sink)
{
	fill(visit, visit+MAX, 0);
	fill(dist, dist+MAX, INF);

	priority_queue<pii, vector<pii>, greater<pii>> que;
	que.push({0, src});
	dist[src] = 0;

	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		if (cur == sink)
			return cost;

		if (visit[cur])
			continue;
		visit[cur] = 1;

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second + cost;

			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				que.push({next_cost, next});
			}
		}
	}
	return INF;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> m >> n >> s >> e1 >> e2;
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}

	int left = dijkstra(s, e1);
	int right = dijkstra(s, e2);
	int mid = dijkstra(e1, e2);

	cout << min(left, right) + mid << '\n';

	return 0;
}
