#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 101
const int INF = 1e9+7;
typedef pair<int, int> pii;

vector<pii> graph[MAX];

vector<int> dijkstra(int s)
{
	vector<int> dist(MAX, INF);
	priority_queue<pii, vector<pii>, greater<pii>> que;
	que.push({0, s});
	dist[s] = 0;

	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second + cost;

			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				que.push({next_cost, next});
			}
		}
	}
	return dist;
}

int main()
{
	int n, m, x, y, z, a, b;

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}
	cin >> a >> b;

	vector<int> A = dijkstra(a);
	vector<int> B = dijkstra(b);

	int min_cost = INF;
	for (int i=n; i>=1; i--) {
		if (i == a || i == b || A[i] == INF || B[i] == INF)
			continue;

		min_cost = min(min_cost, A[i] + B[i]);
	}

	int ans = -1, cur = INF;
	for (int i=n; i>=1; i--) {
		if (i == a || i == b || A[i] == INF || B[i] == INF)
			continue;

		if (A[i] > B[i] || A[i] + B[i] != min_cost)
			continue;

		if (cur >= A[i]) {
			cur = A[i];
			ans = i;
		}
	}
	cout << ans << '\n';

	return 0;
}
