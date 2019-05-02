#include <iostream>
using namespace std;

#define MAX_VAL 51
#define INF 100000000

int graph[MAX_VAL][MAX_VAL], ans[MAX_VAL];

int main()
{
	int n, a, b, idx = 0, min_val = INF;

	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			if (i != j)
				graph[i][j] = INF;

	while (scanf("%d %d", &a, &b) && a != -1)
		graph[a][b] = graph[b][a] = 1;

	for (int k=1; k<=n; ++k)
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=n; ++j)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

	for (int i=1; i<=n; ++i) {
		int max_val = 0;
		for (int j=1; j<=n; ++j)
			max_val = max(max_val, graph[i][j]);

		if (max_val <= min_val) {
			if (max_val != min_val)
				idx = 0;
			min_val = max_val;
			ans[idx++] = i;
		}
	}

	printf("%d %d\n", min_val, idx);
	for (int i=0; i<idx; ++i)
		printf("%d ", ans[i]);

	return 0;
}
