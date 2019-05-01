#include <iostream>
using namespace std;

#define INF 100000000
int graph[101][101];

int main()
{
	int n, m, a, b, cnt;

	scanf("%d %d", &n, &m);
	for (int i=0; i<m; ++i) {
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
	}

	for (int k=1; k<=n; ++k)
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=n; ++j)
				if (graph[i][k] && graph[k][j])
					graph[i][j] = 1;

	for (int i=1; i<=n; ++i) {
		cnt = 0;
		for (int j=1; j<=n; ++j)
			if (graph[i][j] == 0 && graph[j][i] == 0)
				cnt++;
		printf("%d\n", cnt-1);
	}

	return 0;
}
