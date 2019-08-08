#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;
#define MAX 10001
#define ll long long
typedef pair<int, int> pii;
typedef tuple<ll, int, int> tlii;

vector<pii> graph[MAX];
bool visit[MAX][21];
ll dist[MAX][21];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, k, a, b, c;

	cin >> n >> m >> k;
	for (int i=0; i<m; ++i) {
		cin >> a >> b >> c;
		graph[a].push_back({c, b});
		graph[b].push_back({c, a});
	}

	for (int i=0; i<MAX; ++i)
		for (int j=0; j<21; ++j)
			dist[i][j] = LLONG_MAX;

	priority_queue<tlii, vector<tlii>, greater<tlii>> que;
	que.push({0, 1, 0});
	dist[1][0] = 0;

	while (!que.empty()) {
		auto [_, cur, step] = que.top();
		que.pop();

		if (visit[cur][step])
			continue;

		visit[cur][step] = true;
		for (int i=0; i<graph[cur].size(); ++i) {
			int cost = graph[cur][i].first;
			int next = graph[cur][i].second;

			if (step+1 <= k && dist[next][step+1] > dist[cur][step]) {
				dist[next][step+1] = dist[cur][step];
				que.push({dist[next][step+1], next, step+1});
			}

			if (dist[next][step] > dist[cur][step] + cost) {
				dist[next][step] = dist[cur][step] + cost;
				que.push({dist[next][step], next, step});
			}
		}
	}

	ll ans = LLONG_MAX;
	for (int i=1; i<=k; ++i)
		if (visit[n][i] && ans > dist[n][i])
			ans = dist[n][i];

	cout << ans << '\n';

	return 0;
}
