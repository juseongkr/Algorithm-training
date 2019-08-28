#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 100001
const int INF = 1e9+7;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

int n, x, y, u, v, c;
vector<pii> graph[MAX];
int dist[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> x >> y;
	for (int i=0; i<n-1; ++i) {
		cin >> u >> v >> c;
		graph[u].push_back({c, v});
		graph[v].push_back({c, u});
	}

	priority_queue<tiii, vector<tiii>, greater<tiii>> que;
	fill(dist, dist+MAX, INF);
	que.push({0, x, 0});
	dist[x] = 0;

	while (!que.empty()) {
		auto [cost, cur, node] = que.top();
		que.pop();

		if (cur == y) {
			cout << dist[y] - node << '\n';
			break;
		}

		for (int i=0; i<graph[cur].size(); ++i) {
			int next_cost = graph[cur][i].first;
			int next = graph[cur][i].second;

			if (dist[next] > cost + next_cost) {
				dist[next] = cost + next_cost;
				que.push({cost + next_cost, next, max(next_cost, node)});
			}
		}
	}

	return 0;
}
