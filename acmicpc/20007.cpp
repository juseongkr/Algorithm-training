#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001
const int INF = 1e9+7;
typedef pair<int, int> pi;

int n, m, x, y, u, v, z;
vector<pi> graph[MAX];
bool visit[MAX];
int dist[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> x >> y;
	for (int i=0; i<m; ++i) {
		cin >> u >> v >> z;
		graph[u].push_back({v, z});
		graph[v].push_back({u, z});
	}

	fill(dist, dist+MAX, INF);
	priority_queue<pi, vector<pi>, greater<pi>> que;
	que.push({0, y});
	dist[y] = 0;

	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

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

	for (int i=0; i<n; ++i) {
		if (dist[i] > x) {
			cout << "-1\n";
			return 0;
		}
	}

	sort(dist, dist+n);

	int ans = 1, cur = 0;
	for (int i=0; i<n; ++i) {
		if (2 * dist[i] + cur > x) {
			cur = 0;
			ans++;
		}
		cur += dist[i] * 2;
	}
	cout << ans << '\n';

	return 0;
}
