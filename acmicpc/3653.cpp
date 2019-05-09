#include <iostream>
using namespace std;

#define MAX 200002
long long tree[MAX];
int num[MAX];

void update(int i, long long diff)
{
	while (i <= MAX) {
		tree[i] += diff;
		i += (i & -i);
	}
}

long long sum(int i)
{
	long long ret = 0;
	while (i) {
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}

int main()
{
	int t, n, m, v;

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i=0; i<MAX; ++i)
			tree[i] = num[i] = 0;

		for (int i=1; i<=n; ++i) {
			num[i] = n+1-i;
			update(i, 1);
		}

		int next = n+1;
		for (int i=0; i<m; ++i) {
			scanf("%d", &v);

			long long ans = sum(MAX-1) - sum(num[v]);
			printf("%lld ", ans);

			update(num[v], -1);
			num[v] = next++;
			update(num[v], 1);
		}
		printf("\n");
	}

	return 0;
}
