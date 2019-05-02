#include <iostream>
using namespace std;

#define MAX 251
#define INF 100000000

int graph[MAX][MAX];

int main()
{
	int n, m, u, v, b, k;

	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			if (i != j)
				graph[i][j] = INF;

	for (int i=0; i<m; ++i) {
		scanf("%d %d %d", &u, &v, &b);
		graph[u][v] = 0;
		if (b == 0)
			graph[v][u] = 1;
		else
			graph[v][u] = 0;
	}

	for (int k=1; k<=n; ++k)
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=n; ++j)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

	scanf("%d", &k);
	for (int i=0; i<k; ++i) {
		scanf("%d %d", &u, &v);
		printf("%d\n", graph[u][v]);
	}

	return 0;
}
