#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 101
typedef pair<int, int> pii;
const int INF = 1e9+7;

pii dist[MAX];
vector<pii> graph[MAX];

int main()
{
	int n, m, a, b, c, d, e;

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> a >> b >> c >> d >> e;
		if (e > 10)
			c += d * (e - 10);
		graph[a].push_back({b, c});
	}

	for (int i=0; i<MAX; ++i)
		dist[i] = {INF, INF};

	queue<int> que;
	dist[1] = {0, 1};
	que.push(1);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i=0; i<graph[cur].size(); ++i) {
			auto [next, time] = graph[cur][i];

			if (dist[next].first == dist[cur].first + time) {
				if (dist[next].second > dist[cur].second + 1) {
					dist[next].second = dist[cur].second + 1;
					que.push(next);
				}
			} else if (dist[next].first > dist[cur].first + time) {
				dist[next].first = dist[cur].first + time;
				dist[next].second = dist[cur].second + 1;
				que.push(next);
			}
		}
	}

	if (dist[n].first == INF)
		cout << "It is not a great way.\n";
	else
		cout << dist[n].first << " " << dist[n].second << '\n';

	return 0;
}
