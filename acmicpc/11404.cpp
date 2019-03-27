#include <iostream>
#include <limits.h>
using namespace std;

int city[101][101];
int n, m;

void solve()
{
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			for (int k=1; k<=n; ++k) {
				if (city[j][i] != INT_MAX && city[i][k] != INT_MAX)
					city[j][k] = min(city[j][k], city[j][i] + city[i][k]);
			}
		}
	}
}

int main()
{
	int a, b, w;
	
	scanf("%d %d", &n, &m);

	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			city[i][j] = INT_MAX;

	for (int i=0; i<m; ++i) {
		scanf("%d %d %d", &a, &b, &w);
		if (city[a][b] > w)
			city[a][b] = w;
	}

	solve();

	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			if (i == j || city[i][j] == INT_MAX)
				printf("0 ");
			else
				printf("%d ", city[i][j]);
		}
		printf("\n");
	}

	return 0;
}
