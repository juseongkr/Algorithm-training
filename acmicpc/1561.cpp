#include <iostream>
using namespace std;
#define MAX 10001
#define ll long long

int num[MAX];

int main()
{
	int n, m;

	cin >> n >> m;
	for (int i=0; i<m; ++i)
		cin >> num[i];

	if (n <= m) {
		cout << n;
		return 0;
	}

	ll time = -1;
	ll l = 0, r = 60000000000;
	while (l <= r) {
		ll mid = (l + r)/2;
		ll sum = m;
		for (int i=0; i<m; ++i)
			sum += mid/num[i];

		if (sum < n) {
			l = mid+1;
		} else {
			time = mid;
			r = mid-1;
		}
	}

	ll child = m;
	for (int i=0; i<m; ++i)
		child += (time-1)/num[i];

	for (int i=0; i<m; ++i) {
		if (time % num[i] == 0)
			child++;

		if (child == n) {
			cout << i+1 << '\n';
			break;
		}
	}

	return 0;
}
