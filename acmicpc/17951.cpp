#include <iostream>
using namespace std;
#define MAX 100001
const int INF = 1e9+7;

int n, k, ans;
int num[MAX];

bool check(int mid)
{
	int ret = 0, cnt = 1, mi = INF;
	for (int i=0; i<n; ++i) {
		if (ret + num[i] < mid) {
			ret += num[i];
		} else {
			mi = min(mi, ret + num[i]);
			ret = 0;
			cnt++;
		}
	}

	if (cnt > k) {
		ans = max(ans, mi);
		return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	int l = 0, r = INF;
	while (l <= r) {
		int mid = (l+r)/2;
		if (check(mid))
			r = mid-1;
		else
			l = mid+1;
	}
	cout << ans << '\n';

	return 0;
}
