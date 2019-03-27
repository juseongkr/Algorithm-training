#include <iostream>
using namespace std;

int main()
{
	long long tree[1000001];
	long long n, m, max_val = 0;
	long long lo, hi, mid, sum, ret = 0;

	scanf("%lld %lld", &n, &m);
	for (int i=0; i<n; ++i) {
		scanf("%lld", &tree[i]);
		max_val = max(max_val, tree[i]);
	}
	
	lo = 0;
	hi = max_val;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		sum = 0;
		for (int i=0; i<n; ++i)
			if (mid < tree[i])
				sum += tree[i] - mid;
		
		if (sum >= m) {
			if (ret < mid)
				ret = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}

	printf("%lld\n", ret);

	return 0;
}
