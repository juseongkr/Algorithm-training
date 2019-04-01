#include <iostream>
using namespace std;

int sum[3][100001];

int main()
{
	int n, q, v, a, b;

	scanf("%d %d", &n, &q);
	for (int i=0; i<n; ++i) {
		scanf("%d", &v);
		for (int j=0; j<3; ++j)
			if (j+1 == v)
				sum[j][i+1] = sum[j][i] + 1;
			else
				sum[j][i+1] = sum[j][i];
	}

	for (int i=0; i<q; ++i) {
		scanf("%d %d", &a, &b);
		for (int j=0; j<3; ++j)
			printf("%d ", sum[j][b] - sum[j][a-1]);
		printf("\n");
	}

	return 0;
}
