#include <iostream>
#include <climits>
using namespace std;
#define MAX 300001

int n, m, max_val;
int num[MAX];

bool check(int k)
{
	int ret = 0;
	for (int i=0; i<m; ++i) {
		ret += num[i] / k;
		if (num[i] % k > 0)
			ret++;
	}

	if (ret <= n)
		return true;
	return false;
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> num[i];
		max_val = max(max_val, num[i]);
	}

	int ans = INT_MAX;
	int l = 0, r = max_val;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			ans = min(ans, mid);
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans << '\n';

	return 0;
}
