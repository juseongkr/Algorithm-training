#include <iostream>
using namespace std;

int n, m, a, b;
int graph[101][101];

void solve()
{
	for (int k=1; k<=n; ++k) {
		for (int i=1; i<=n; ++i) {
			for (int j=1; j<=n; ++j) {
				if (i == j || graph[i][k] == 0 || graph[k][j] == 0)
					continue;

				if (graph[i][j] == 0)
					graph[i][j] = graph[i][k] + graph[k][j];
				else
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
}

int main()
{
	int ans = 0, ret = 9999999;
	int result[101] = {0, };

	scanf("%d %d", &n, &m);

	for (int i=0; i<m; ++i) {
		scanf("%d %d", &a, &b);
		graph[a][b] = graph[b][a] = 1;
	}

	solve();

	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j)
			result[i] += graph[i][j];

		if (ret > result[i]) {
			ret = result[i];
			ans = i;
		}
	}

	printf("%d\n", ans);

	return 0;
}
