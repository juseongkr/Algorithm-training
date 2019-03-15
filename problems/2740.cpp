#include <iostream>
using namespace std;

int main()
{
	int a[101][101], b[101][101], c[101][101];
	int n, m, k;

	scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			scanf("%d", &a[i][j]);

	scanf("%d %d", &m, &k);
	for (int i=0; i<m; ++i)
		for (int j=0; j<k; ++j)
			scanf("%d", &b[i][j]);

	for (int i=0; i<n; ++i)
		for (int j=0; j<k; ++j)
			for (int z=0; z<m; ++z)
				c[i][j] += a[i][z] * b[z][j];

	for (int i=0; i<n; ++i) {
		for (int j=0; j<k; ++j) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}

	return 0;
}
