#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_VAL 101
#define INF 100000000

int dist[MAX_VAL][MAX_VAL];
int max_val[MAX_VAL], visit[MAX_VAL];

int main()
{
	vector<int> ans;
	int n, m, a, b, idx;

	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			if (i != j)
				dist[i][j] = INF;

	for (int i=0; i<m; ++i) {
		scanf("%d %d", &a, &b);
		dist[a][b] = dist[b][a] = 1;
	}

	for (int k=1; k<=n; ++k)
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			if (dist[i][j] > max_val[i] && dist[i][j] != INF)
				max_val[i] = dist[i][j];

	for (int i=1; i<=n; ++i) {
		if (visit[i] == 0) {
			idx = i;
			for (int j=1; j<=n; ++j) {
				if (dist[i][j] != INF) {
					visit[j] = 1;
					if (max_val[idx] > max_val[j])
						idx = j;
				}
			}
			ans.push_back(idx);
		}
	}

	sort(ans.begin(), ans.end());

	printf("%lu\n", ans.size());
	for (int i=0; i<ans.size(); ++i)
		printf("%d\n", ans[i]);

	return 0;
}
