#include <iostream>
using namespace std;

int sum[1025][1025];

int main()
{
	int n, m, v;
	int x1, y1, x2, y2;
	
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			scanf("%d", &v);
			sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + v;
		}
	}

	for (int i=0; i<m; ++i) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", sum[x2][y2] + sum[x1-1][y1-1] - sum[x1-1][y2] - sum[x2][y1-1]);
	}

	return 0;
}
