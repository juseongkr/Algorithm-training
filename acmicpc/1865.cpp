#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define MAX 501

int main()
{
	int T, n, m, w, s, e, t;
	bool cycle;

	scanf("%d", &T);
	while (T--) {
		vector<pair<int, int>> graph[MAX];
		int dist[MAX];

		scanf("%d %d %d", &n, &m, &w);
		for (int i=0; i<m; ++i) {
			scanf("%d %d %d", &s, &e, &t);
			graph[s].push_back({e, t});
			graph[e].push_back({s, t});
		}

		for (int i=0; i<w; ++i) {
			scanf("%d %d %d", &s, &e, &t);
			graph[s].push_back({e, -t});
		}

		fill(dist, dist+n, INT_MAX);
		cycle = false;
		dist[0] = 0;

		for (int k=1; k<=n; ++k) {
			for (int i=1; i<=n; ++i) {
				for (int j=0; j<graph[i].size(); ++j) {
					int next = graph[i][j].first;
					int cost = graph[i][j].second;

					if (dist[i] != INT_MAX && dist[next] > dist[i] + cost) {
						if (k == n)
							cycle = true;
						dist[next] = dist[i] + cost;
					}
				}
			}
		}

		if (cycle)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
