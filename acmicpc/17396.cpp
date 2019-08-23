#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define MAX 100001
typedef pair<long long, int> pli;

int visit[MAX];
long long dist[MAX];
vector<pli> graph[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, a, b, c;

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> visit[i];
	visit[n-1] = 0;

	for (int i=0; i<m; ++i) {
		cin >> a >> b >> c;
		graph[a].push_back({c, b});
		graph[b].push_back({c, a});
	}

	priority_queue<pli, vector<pli>, greater<pli>> que;
	fill(dist, dist+MAX, LLONG_MAX);
	que.push({0, 0});
	dist[0] = 0;

	while (!que.empty()) {
		long long cost = que.top().first;
		int cur = que.top().second;
		que.pop();

		if (visit[cur])
			continue;
		visit[cur] = 1;

		for (int i=0; i<graph[cur].size(); ++i) {
			long long next_cost = graph[cur][i].first;
			int next = graph[cur][i].second;

			if (dist[next] > next_cost + cost) {
				dist[next] = next_cost + cost;
				que.push({dist[next], next});
			}
		}
	}
	if (dist[n-1] == LLONG_MAX)
		cout << "-1\n";
	else
		cout << dist[n-1] << '\n';

	return 0;
}
