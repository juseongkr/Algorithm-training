#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001
#define ll long long
const ll INF = 1e18+7;
typedef pair<ll, ll> pii;

vector<pii> graph[MAX];
bool visit[MAX];
ll dist[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, m, k, x, y, z, t;

	cin >> n >> m >> k;
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		graph[y].push_back({x, z});
	}

	priority_queue<pii, vector<pii>, greater<pii>> que;
	fill(dist, dist+MAX, INF);

	for (int i=0; i<k; ++i) {
		cin >> t;
		que.push({0, t});
		dist[t] = 0;
	}

	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		if (visit[cur])
			continue;
		visit[cur] = 1;

		for (int i=0; i<graph[cur].size(); ++i) {
			ll next = graph[cur][i].first;
			ll next_cost = graph[cur][i].second + cost;

			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				que.push({next_cost, next});
			}
		}
	}

	ll mi = INF;
	for (int i=1; i<=n; ++i)
		mi = min(mi, -dist[i]);

	for (int i=1; i<=n; ++i) {
		if (-mi == dist[i]) {
			cout << i << '\n';
			break;
		}
	}
	cout << -mi << '\n';

	return 0;
}
