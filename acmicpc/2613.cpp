#include <iostream>
using namespace std;
#define MAX 301

int n, m, l, r;
int num[MAX];

bool check(int mid)
{
	int sum = 0, cnt = 1;
	for (int i=0; i<n; ++i) {
		if (sum + num[i] <= mid) {
			sum += num[i];
		} else {
			sum = num[i];
			cnt++;
		}
	}
	return cnt <= m;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> num[i];
		r += num[i];
		l = max(l, num[i]);
	}

	while (l <= r) {
		int mid = (l+r)/2;
		if (check(mid))
			r = mid-1;
		else
			l = mid+1;
	}
	cout << l << '\n';

	int sum = 0, cnt = 0, part = 1;
	for (int i=0; i<n; ++i) {
		if (sum + num[i] > l || m-part == n-i) {
			cout << cnt << " ";
			sum = num[i];
			part++;
			cnt = 1;
		} else {
			sum += num[i];
			cnt++;
		}
	}
	cout << cnt << '\n';

	return 0;
}
