#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
#define MAX 5001
const int INF = 1e9+7;
typedef pair<int, int> pi;

int n, m, x, y, z;
vector<pi> graph[MAX];
bool visit[MAX];
int dist[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}
	cin >> x >> y;

	fill(dist, dist+MAX, INF);
	priority_queue<pi, vector<pi>, greater<pi>> que;
	que.push({0, x});
	dist[x] = 0;

	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		if (visit[cur])
			continue;
		visit[cur] = 1;

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second + cost;

			if (!visit[next] && dist[next] > next_cost) {
				dist[next] = next_cost;
				que.push({next_cost, next});
			}
		}
	}

	cout << dist[y] << '\n';

	return 0;
}
