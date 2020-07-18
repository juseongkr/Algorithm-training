#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
#define MAX 50001
const int INF = 1e9+7;
typedef pair<int, int> pii;

int n, m, x, y, z;
int dist[MAX];
bool visit[MAX];
vector<pii> graph[MAX];

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

	fill(dist, dist+MAX, INF);
	priority_queue<pii, vector<pii>, greater<pii>> que;
	que.push({0, 1});
	dist[1] = 0;

	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		if (cur == n) {
			cout << cost << '\n';
			return 0;
		}

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

	return 0;
}
