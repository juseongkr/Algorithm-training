#include <iostream>
using namespace std;

int graph[401][401];

int main()
{
	int n, k, a, b, s;

	scanf("%d %d", &n, &k);
	for (int i=0; i<k; ++i) {
		scanf("%d %d", &a, &b);
		graph[a][b] = -1;
		graph[b][a] = 1;
	}

	for (int m=1; m<=n; ++m) {
		for (int i=1; i<=n; ++i) {
			for (int j=1; j<=n; ++j) {
				if (i == j || j == m || m == i)
					continue;

				if (graph[i][j] == 0) {
					if (graph[i][m] == 1 && graph[m][j] == 1)
						graph[i][j] = 1;
					else if (graph[i][m] == -1 && graph[m][j] == -1)
						graph[i][j] = -1;
				}
			}
		}
	}

	scanf("%d", &s);
	for (int i=0; i<s; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);

		printf("%d\n", graph[x][y]);
	}

	return 0;
}
