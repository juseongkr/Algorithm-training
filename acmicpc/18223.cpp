#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
#define MAX 5001
const int INF = 1e9+7;
typedef pair<int, int> pi;

int dist[MAX];
bool visit[MAX];
int n, m, p, x, y, z;
vector<pi> graph[MAX];

int dijkstra(int start, int dest)
{
	fill(dist, dist+MAX, INF);
	fill(visit, visit+MAX, 0);

	priority_queue<pi, vector<pi>, greater<pi>> que;
	que.push({0, start});
	dist[start] = 0;

	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		if (visit[cur])
			continue;
		visit[cur] = 1;

		if (cur == dest)
			return cost;

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

	cin >> n >> m >> p;
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}

	if (dijkstra(1, n) >= dijkstra(1, p) + dijkstra(p, n))
		cout << "SAVE HIM\n";
	else
		cout << "GOOD BYE\n";

	return 0;
}
