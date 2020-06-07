#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001
#define ll long long
const ll INF = 1e18+7;
typedef pair<ll, int> pi;
typedef tuple<int, int, int> tp;

ll k;
ll dist[MAX];
bool visit[MAX];
int n, m, a, b, c, t;
vector<tp> graph[MAX];

bool check(int mid)
{
	fill(visit, visit+MAX, 0);
	fill(dist, dist+MAX, INF);

	priority_queue<pi, vector<pi>, greater<pi>> que;
	dist[0] = 0;
	que.push({0, 0});

	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		if (visit[cur] || dist[cur] > k)
			continue;
		visit[cur] = 1;

		for (int i=0; i<graph[cur].size(); ++i) {
			auto [next, c, t] = graph[cur][i];

			if (mid > t && (1LL*c*(mid-t) > k || 1LL*(mid-t)*(mid-t) > k))
				continue;

			ll next_cost = mid > t ? 1LL*c*(mid-t)*(mid-t) : 0;
			if (dist[next] > dist[cur] + next_cost) {
				dist[next] = dist[cur] + next_cost;
				que.push({dist[next], next});
			}
		}
	}

	return dist[n-1] <= k;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i=0; i<m; ++i) {
		cin >> a >> b >> c >> t;
		a--;
		b--;
		graph[a].push_back({b, c, t});
		graph[b].push_back({a, c, t});
	}

	int l = 1, r = 1e9+7;
	while (l <= r) {
		int mid = (l+r)/2;
		if (check(mid))
			l = mid+1;
		else
			r = mid-1;
	}
	cout << l-1 << '\n';

	return 0;
}
