#include <iostream>
using namespace std;

int sum [100001];

int main()
{
	int n, m, t, a, b;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &t);
		sum[i+1] = sum[i] + t;
	}

	scanf("%d", &m);
	for (int i=0; i<m; ++i) {
		scanf("%d %d", &a, &b);
		printf("%d\n", sum[b] - sum[a-1]);
	}

	return 0;
}
