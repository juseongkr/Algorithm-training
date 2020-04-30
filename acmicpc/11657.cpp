#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

#define MAX_VAL 501

int main()
{
	vector<pair<int, int>> map[MAX_VAL];
	long long dist[MAX_VAL];
	int n, m, a, b, w;
	bool cycle = false;

	scanf("%d %d", &n, &m);
	for (int i=0; i<m; ++i) {
		scanf("%d %d %d", &a, &b, &w);
		map[a-1].push_back({b-1, w});
	}

	fill(dist, dist+n, INT_MAX);
	dist[0] = 0;

	for (int k=0; k<n; ++k) {
		for (int i=0; i<n; ++i) {
			for (int j=0; j<map[i].size(); ++j) {
				int next = map[i][j].first;
				int cost = map[i][j].second;

				if (dist[i] != INT_MAX && dist[next] > dist[i] + cost) {
					if (k == n-1)
						cycle = true;
					dist[next] = dist[i] + cost;
				}
			}
		}
	}

	if (cycle) {
		printf("-1\n");
	} else {
		for (int i=1; i<n; ++i) {
			if (dist[i] != INT_MAX)
				printf("%lld\n", dist[i]);
			else
				printf("-1\n");
		}
	}

	return 0;
}
