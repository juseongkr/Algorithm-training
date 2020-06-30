#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10001
const int INF = 1e9+7;
typedef pair<int, int> pi;

int n, m, x, y, z;
int dist[MAX];
bool visit[MAX];
vector<pi> graph[MAX];

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
	priority_queue<pi, vector<pi>, greater<pi>> que;
	que.push({0, 0});
	dist[0] = 0;

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

	fill(visit, visit+MAX, 0);

	queue<int> q;
	visit[n-1] = 1;
	q.push(n-1);

	long long ans = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second;

			if (dist[next] + next_cost == dist[cur]) {
				ans += next_cost;
				if (!visit[next]) {
					q.push(next);
					visit[next] = 1;
				}
			}
		}
	}
	cout << ans * 2 << '\n';

	return 0;
}
