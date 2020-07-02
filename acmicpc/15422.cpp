#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 50001
const long long INF = 1e18+7;
typedef tuple<long long, int, int> tp;

int n, m, f, s, t, x, y, z;
vector<tp> graph[MAX][2];
long long dist[MAX][2];
bool visit[MAX][2];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> f >> s >> t;
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		graph[x][0].push_back({y, z, 0});
		graph[y][0].push_back({x, z, 0});
		graph[x][1].push_back({y, z, 1});
		graph[y][1].push_back({x, z, 1});
	}

	for (int i=0; i<f; ++i) {
		cin >> x >> y;
		graph[x][0].push_back({y, 0, 1});
	}

	for (int i=0; i<n; ++i)
		dist[i][0] = dist[i][1] = INF;

	priority_queue<tp, vector<tp>, greater<tp>> que;
	que.push({0, s, 0});
	dist[s][0] = 0;

	while (!que.empty()) {
		auto [cost, cur, tick] = que.top();
		que.pop();

		if (visit[cur][tick])
			continue;
		visit[cur][tick] = 1;

		for (int i=0; i<graph[cur][tick].size(); ++i) {
			auto [next, next_cost, next_tick] = graph[cur][tick][i];

			if (dist[next][next_tick] > dist[cur][tick] + next_cost) {
				dist[next][next_tick] = dist[cur][tick] + next_cost;
				que.push({dist[next][next_tick], next, next_tick});
			}
		}
	}

	cout << min(dist[t][0], dist[t][1]) << '\n';

	return 0;
}
