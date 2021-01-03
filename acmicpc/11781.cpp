#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 5001
#define ll long long
const ll INF = 1e18+7;
typedef tuple<int, ll, bool> tp;
typedef pair<ll, int> pi;

int n, m, x, y;
ll dist[MAX], s, e, l;
bool visit[MAX], t1, t2;
vector<tp> graph[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> s >> e;
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> l >> t1 >> t2;
		l *= 2;
		graph[x].push_back({y, l, t1});
		graph[y].push_back({x, l, t2});
	}
	s *= 2;
	e *= 2;

	fill(dist, dist+n+1, INF);
	priority_queue<pi, vector<pi>, greater<pi>> que;
	que.push({0, 1});
	dist[1] = 0;

	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		if (visit[cur])
			continue;
		visit[cur] = 1;

		for (int i=0; i<graph[cur].size(); ++i) {
			auto [next, len, busy] = graph[cur][i];
			ll next_cost = cost + len;

			if (busy) {
				if (cost < s && cost + len >= s) {
					ll dif = s - cost;
					ll last = len - dif;
					ll jam = min(e-s, last*2);
					ll ed = last - jam/2;
					next_cost = cost + dif + jam + ed;
				} else if (s <= cost && cost < e) {
					ll jam = min(e-cost, len*2);
					ll ed = len - jam/2;
					next_cost = cost + jam + ed;
				}
			}

			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				que.push({next_cost, next});
			}
		}
	}

	ll ans = 0;
	for (int i=1; i<=n; ++i)
		ans = max(ans, dist[i]);

	cout << ans/2;
	if (ans % 2)
		cout << ".5";

	return 0;
}
