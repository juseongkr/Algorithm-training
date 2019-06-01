#include <iostream>
using namespace std;

int main()
{
	int n, k, ans;

	cin >> n >> k;
	int l = 1, r = k;
	while (l <= r) {
		int cnt = 0;
		int mid = (l + r)/2;
		for (int i=1; i<=n; ++i)
			cnt += min(mid/i, n);

		if (cnt >= k) {
			r = mid-1;
			ans = mid;
		} else {
			l = mid+1;
		}
	}
	cout << ans << '\n';

	return 0;
}
