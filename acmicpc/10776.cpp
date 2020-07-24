#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 2001
#define K 201
typedef tuple<int, int, int> tp;
const int INF = 1e9+7;

int k, n, m, x, y, z, h, s, e;
vector<tp> graph[MAX];
bool visit[MAX][K];
int dist[MAX][K];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> k >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z >> h;
		graph[x].push_back({y, z, h});
		graph[y].push_back({x, z, h});
	}
	cin >> s >> e;

	for (int i=1; i<=n; ++i)
		fill(dist[i], dist[i]+K, INF);

	priority_queue<tp, vector<tp>, greater<tp>> que;
	que.push({0, s, k});
	dist[s][k] = 0;

	while (!que.empty()) {
		auto [cost, cur, left] = que.top();
		que.pop();

		if (cur == e) {
			cout << cost << '\n';
			return 0;
		}

		if (visit[cur][left])
			continue;
		visit[cur][left] = 1;

		for (int i=0; i<graph[cur].size(); ++i) {
			auto [next, next_cost, next_left] = graph[cur][i];
			next_cost += cost;

			if (left > next_left && dist[next][left-next_left] > next_cost) {
				dist[next][left-next_left] = next_cost;
				que.push({next_cost, next, left-next_left});
			}
		}
	}
	cout << "-1\n";

	return 0;
}
