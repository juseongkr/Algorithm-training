#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001
const long long INF = 1e18+7;
typedef pair<long long, long long> pll;

int h[MAX];
int n, m, d, e, x, y, z;
vector<pll> graph[MAX];

vector<long long> dijkstra(int k)
{
	vector<long long> dist(n+1, INF);
	vector<bool> visit(n+1, 0);
	priority_queue<pll, vector<pll>, greater<pll>> que;
	que.push({0, k});
	dist[k] = 0;

	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		if (visit[cur])
			continue;
		visit[cur] = 1;

		for (int i=0; i<graph[cur].size();  ++i) {
			int next = graph[cur][i].first;
			long long next_cost = graph[cur][i].second + cost;
			
			if  (dist[next] > next_cost) {
				dist[next] = next_cost;
				que.push({next_cost, next});
			}
		}
	}
	return dist;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> d >> e;
	for (int i=1; i<=n; ++i)
		cin >> h[i];

	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		if (h[x] < h[y])
			graph[x].push_back({y, z});
		if (h[x] > h[y])
			graph[y].push_back({x, z});
	}

	auto d1 = dijkstra(1);
	auto d2 = dijkstra(n);

	long long ans = -INF;
	for (int i=1; i<=n; ++i)
		if (d1[i] < INF && d2[i] < INF)
			ans = max(ans, (long long)(h[i] * e - (d1[i] + d2[i]) * d));

	if (ans == -INF)
		cout << "Impossible\n";
	else
		cout << ans <<  '\n';

	return 0;
}
