#include <iostream>
using namespace std;

int main()
{
	int sum[100001] = {0, };
	int n, m, num, a, b;

	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; ++i) {
		scanf("%d", &num);
		sum[i+1] = sum[i] + num;
	}

	for (int i=0; i<m; ++i) {
		scanf("%d %d", &a, &b);
		printf("%d\n", sum[b+1] - sum[a]);
	}

	return 0;
}
