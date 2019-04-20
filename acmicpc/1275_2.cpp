#include <iostream>
using namespace std;

long long num[100001], tree[400004];
int n, m;

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
	long long x, y, a, b, ans;

	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; ++i) {
		scanf("%lld", &num[i]);
		update(i, num[i]);
	}

	for (int i=0; i<m; ++i) {
		scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
		if (x > y)
			swap(x, y);
		long long ans = sum(y) - sum(x-1);
		printf("%lld\n", ans);
		long long diff = b - num[a];
		update(a, diff);
		num[a] = b;
	}

	return 0;
}
