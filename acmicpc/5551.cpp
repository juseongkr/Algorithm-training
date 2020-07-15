#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define MAX 3001
#define EDGE 100001
const int INF = 1e9+7;
typedef pair<int, int> pii;

int n, m, k, p;
int x[EDGE], y[EDGE], z[EDGE], dist[MAX];
vector<pii> graph[MAX];
bool visit[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i=0; i<m; ++i) {
		cin >> x[i] >> y[i] >> z[i];
		graph[x[i]].push_back({y[i], z[i]});
		graph[y[i]].push_back({x[i], z[i]});
	}

	fill(dist, dist+MAX, INF);
	priority_queue<pii, vector<pii>, greater<pii>> que;
	for (int i=0; i<k; ++i) {
		cin >> p;
		dist[p] = 0;
		que.push({0, p});
	}

	int ans = 0;
	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		if (visit[cur])
			continue;
		visit[cur] = 1;

		ans = max(ans, cost);
		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second + cost;

			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				que.push({next_cost, next});
			}
		}
	}

	for (int i=0; i<m; ++i) {
		if (dist[x[i]] > dist[y[i]])
			swap(x[i], y[i]);

		if (dist[x[i]] + z[i] > dist[y[i]])
			ans = max(ans, (int)round((dist[x[i]] + dist[y[i]] + z[i]) / 2.0));
	}

	cout << ans << '\n';

	return 0;
}
