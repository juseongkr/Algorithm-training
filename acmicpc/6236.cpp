#include <iostream>
using namespace std;
#define MAX 100001
const int INF = 1e9+7;

int n, m, mx, num[MAX];

bool check(int mid)
{
	if (mx > mid)
		return false;

	int sum = 0, cnt = 0;
	for (int i=0; i<n; ++i) {
		sum += num[i];
		if (sum > mid) {
			sum = num[i];
			cnt++;
		}
	}

	return cnt < m;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> num[i];
		mx = max(mx, num[i]);
	}

	if (n == m) {
		cout << mx << '\n';
		return 0;
	}

	int l = mx, r = INF;
	while (l <= r) {
		int mid = (l+r)/2;
		if (check(mid))
			r = mid-1;
		else
			l = mid+1;
	}

	cout << l << '\n';

	return 0;
}
