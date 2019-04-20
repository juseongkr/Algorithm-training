#include <iostream>
using namespace std;

long long num[2000001], tree[4000002];
long long a, b, c;
int n, m, k;

void update(int i, long long diff)
{
	while (i <= n) {
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
	scanf("%d %d %d", &n, &m, &k);
	for (int i=1; i<=n; ++i) {
		scanf("%lld", &num[i]);
		update(i, num[i]);
	}

	for (int i=0; i<m+k; ++i) {
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1) {
			long long diff = c - num[b];
			update(b, diff);
			num[b] = c;
		} else {
			long long ans = sum(c) - sum(b-1);
			printf("%lld\n", ans);
		}
	}

	return 0;
}
