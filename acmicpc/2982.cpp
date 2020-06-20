#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001
typedef pair<int, int> pii;
const int INF = 1e9+7;

int n, m, a, b, k, g, x, y, z;
int go[MAX], dist[MAX], map[MAX][MAX], gdist[MAX][MAX];
vector<pii> graph[MAX];
bool visit[MAX];

int check(int cur, int next, int cost)
{
	int l = gdist[cur][next] - map[cur][next];
	int r = gdist[cur][next];

	cost += k;
	if (l <= cost && cost <= r)
		return r - cost;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> a >> b >> k >> g;
	for (int i=0; i<g; ++i)
		cin >> go[i];

	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
		map[x][y] = map[y][x] = z;
	}

	int time = 0;
	for (int i=0; i<g-1; ++i) {
		int l = go[i], r = go[i+1];
		gdist[l][r] = gdist[r][l] = (time += map[l][r]);
	}

	fill(dist, dist+MAX, INF);
	priority_queue<pii, vector<pii>, greater<pii>> que;
	que.push({0, a});
	dist[a] = 0;

	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		if (visit[cur])
			continue;
		visit[cur] = 1;

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second + cost + check(cur, next, cost);

			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				que.push({next_cost, next});
			}
		}
	}

	cout << dist[b] << '\n';

	return 0;
}
