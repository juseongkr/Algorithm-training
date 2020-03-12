#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001
typedef pair<int, int> pi;
const int INF = 1e9+7;
const int S = 1, T = 2;

int n, m, x, y, z;
vector<pi> graph[MAX];
int dist[MAX], dp[MAX];
bool visit[MAX];

int main()
{
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}

	for (int i=0; i<MAX; ++i)
		dist[i] = INF;

	priority_queue<pi, vector<pi>, greater<pi>> que;
	que.push({0, T});
	dist[T] = 0;
	dp[T] = 1;

	while (!que.empty()) {
		auto [cost, cur] = que.top();
		que.pop();

		if (visit[cur])
			continue;
		visit[cur] = 1;

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second + cost;

			if (dist[next] < cost)
				dp[cur] += dp[next];

			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				que.push({next_cost, next});
			}
		}
	}
	cout << dp[S] << '\n';

	return 0;
}
