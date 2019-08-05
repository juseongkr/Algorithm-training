#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001
typedef pair<int, int> pii;

vector<pii> graph[MAX];
priority_queue<int> dist[MAX];

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
	}
	priority_queue<pii, vector<pii>, greater<pii>> que;
	que.push({0, 1});
	dist[1].push(0);

	while (!que.empty()) {
		int cost = que.top().first;
		int cur = que.top().second;
		que.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			int next_cost = graph[cur][i].first;
			int next = graph[cur][i].second;

			if (dist[next].size() < k || dist[next].top() > cost + next_cost) {
				if (dist[next].size() == k)
					dist[next].pop();

				dist[next].push(cost + next_cost);
				que.push({cost + next_cost, next});
			}
		}
	}

	for (int i=1; i<=n; ++i) {
		if (dist[i].size() != k)
			cout << "-1\n";
		else
			cout << dist[i].top() << '\n';
	}

	return 0;
}
