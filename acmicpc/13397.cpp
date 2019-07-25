#include <iostream>
using namespace std;
#define MAX 5001

int num[MAX];
int n, m, max_val;

bool check(int k)
{
	int ret = 1;
	int h = num[0], l = num[0];
	for (int i=1; i<n; ++i) {
		h = max(h, num[i]);
		l = min(l, num[i]);
		if (h-l > k) {
			l = h = num[i];
			ret++;
		}
	}
	if (ret <= m)
		return true;
	return false;
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> num[i];
		max_val = max(max_val, num[i]);
	}

	int l = 0, r = max_val;
	int ans = max_val;
	while (l <= r) {
		int mid = (l+r)/2;
		if (check(mid)) {
			r = mid - 1;
			ans = mid;
		} else {
			l = mid + 1;
		}
	}
	cout << ans << '\n';

	return 0;
}
