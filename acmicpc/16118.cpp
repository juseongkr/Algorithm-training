#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 4001
typedef pair<int, int> pi;
typedef tuple<int, int, int> tp;
const int INF = 2 * 1e9+7;

int n, m, x, y, z;
bool visit_f[MAX], visit_w[MAX][2];
int fox[MAX], wolf[MAX][2];
vector<pi> graph[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		graph[x].push_back({y, z * 2});
		graph[y].push_back({x, z * 2});
	}

	fill(fox, fox+n+1, INF);
	for (int i=0; i<=n; ++i)
		for (int j=0; j<2; ++j)
			wolf[i][j] = INF;

	priority_queue<tp, vector<tp>, greater<tp>> que;
	que.push({0, 1, 0});
	fox[1] = 0;

	while (!que.empty()) {
		auto [cost, cur, run] = que.top();
		que.pop();

		if (visit_f[cur])
			continue;
		visit_f[cur] = 1;

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second + cost;

			if (fox[next] > next_cost) {
				fox[next] = next_cost;
				que.push({next_cost, next, run});
			}
		}
	}

	que.push({0, 1, 0});
	wolf[1][0] = 0;

	while (!que.empty()) {
		auto [cost, cur, run] = que.top();
		que.pop();

		if (visit_w[cur][run])
			continue;
		visit_w[cur][run] = 1;

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int next_cost = cost + (run ? graph[cur][i].second * 2 : graph[cur][i].second / 2);

			if (wolf[next][!run] > next_cost) {
				wolf[next][!run] = next_cost;
				que.push({next_cost, next, !run});
			}
		}
	}

	int ans = 0;
	for (int i=2; i<=n; ++i)
		if (fox[i] < min(wolf[i][0], wolf[i][1]))
			ans++;

	cout << ans << '\n';

	return 0;
}
