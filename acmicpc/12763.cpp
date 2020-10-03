#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 101
#define MAXT 10001
const int INF = 1e9+7;
typedef tuple<int, int, int> tp;

int n, t, m, a, b, c, d, l;
vector<tp> graph[MAX];
bool visit[MAXT][MAX];
int dist[MAXT][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> t >> m >> l;
	for (int i=0; i<l; ++i) {
		cin >> a >> b >> c >> d;
		graph[a].push_back({b, c, d});
		graph[b].push_back({a, c, d});
	}

	for (int i=0; i<MAXT; ++i)
		fill(dist[i], dist[i]+MAX, INF);

	priority_queue<tp, vector<tp>, greater<tp>> que;
	que.push({0, 0, 1});
	dist[0][0] = 0;

	while (!que.empty()) {
		auto [cost, time, cur] = que.top();
		que.pop();

		if (cur == n) {
			cout << cost << '\n';
			return 0;
		}

		if (visit[time][cur])
			continue;
		visit[time][cur] = 1;

		for (int i=0; i<graph[cur].size(); ++i) {
			auto [next, next_time, next_cost] = graph[cur][i];
			next_time += time;
			next_cost += cost;

			if (next_time <= t && next_cost <= m && !visit[next_time][next] && dist[next_time][next] > next_cost) {
				dist[next_time][next] = next_cost;
				que.push({next_cost, next_time, next});
			}
		}
	}

	cout << "-1\n";

	return 0;
}
