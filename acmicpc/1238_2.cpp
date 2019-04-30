#include <iostream>
using namespace std;

int main()
{
	int graph[1001][1001];
	int n, m, x, a, b, w, ans = 0;

	scanf("%d %d %d", &n, &m, &x);
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = 1000000;
		}
	}
	
	for (int i=0; i<m; ++i) {
		scanf("%d %d %d", &a, &b, &w);
		if (graph[a][b] > w)
			graph[a][b] = w;
	}

	for (int k=1; k<=n; ++k)
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=n; ++j)
				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];

	for (int i=1; i<=n; ++i)
		ans = max(ans, graph[i][x] + graph[x][i]);

	printf("%d\n", ans);

	return 0;
}
