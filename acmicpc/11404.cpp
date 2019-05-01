#include <iostream>
using namespace std;

#define MAX_VAL 100000000

int main()
{
	int dist[101][101];
	int n, m, a, b, w;
	
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			dist[i][j] = MAX_VAL;

	for (int i=0; i<m; ++i) {
		scanf("%d %d %d", &a, &b, &w);
		dist[a-1][b-1] = min(dist[a-1][b-1], w);
	}

	for (int k=0; k<n; ++k)
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (i == j || dist[i][j] == MAX_VAL)
				printf("0 ");
			else
				printf("%d ", dist[i][j]);
		}
		printf("\n");
	}

	return 0;
}
