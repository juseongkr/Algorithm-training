#include <iostream>
using namespace std;

int sum[1001][1001];

int main()
{
	int r, c, q, v;
	int x1, x2, y1, y2, ret, div;

	scanf("%d %d %d", &r, &c, &q);

	for (int i=0; i<r; ++i) {
		for (int j=0; j<c; ++j) {
			scanf("%d", &v);
			sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] +  v;
		}
	}

	for (int i=0; i<q; ++i) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		ret = sum[x2][y2] + sum[x1-1][y1-1] - sum[x1-1][y2] - sum[x2][y1-1];
		div = (x2 - x1 + 1) * (y2 - y1 + 1);

		printf("%d\n", ret / div);
	}

	return 0;
}
