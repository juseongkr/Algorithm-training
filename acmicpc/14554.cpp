#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 100001
#define ll long long
const ll INF = 1e18+7;
const int MOD = 1e9+9;
typedef pair<ll, ll> pi;

int n, m, s, e, x, y, z;
vector<pi> graph[MAX];
bool visit[MAX];
ll dist[MAX];
int cnt[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> s >> e;
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}

	fill(dist, dist+MAX, INF);

	priority_queue<pi, vector<pi>, greater<pi>> que;
	que.push({0, s});
	dist[s] = 0;
	cnt[s] = 1;

	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		if (visit[cur])
			continue;
		visit[cur] = 1;

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			ll next_cost = graph[cur][i].second + cost;

			if (next_cost == dist[next]) {
				cnt[next] = (cnt[cur] + cnt[next]) % MOD;
			}

			if (dist[next] > next_cost) {
				cnt[next] = cnt[cur];
				dist[next] = next_cost;
				que.push({next_cost, next});
			}
		}
	}

	cout << cnt[e] << '\n';

	return 0;
}
