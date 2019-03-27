#include <iostream>
using namespace std;

int main()
{
	long long arr[10001];
	long long n, m, max_val = 0;
	long long lo, hi, mid, ans, sum, ret = 0;

	scanf("%lld", &n);
	for (int i=0; i<n; ++i) {
		scanf("%lld", &arr[i]);
		max_val = max(max_val, arr[i]);
	}
	scanf("%lld", &m);
	
	lo = 0;
	hi = max_val;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		sum = 0;
		for (int i=0; i<n; ++i) {
			if (arr[i] > mid)
				sum += mid;
			else
				sum += arr[i];
		}

		if (sum <= m) {
			if (ret < sum) {
				ret = sum;
				ans = mid;
			}
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}

	printf("%lld\n", ans);

	return 0;
}
