#include <iostream>
#include <climits>
using namespace std;

int main()
{
	long long x, y, z;

	cin >> x >> y;
	z = 100 * y / x;
	if (z >= 99) {
		cout << "-1\n";
		return 0;
	}

	long long l = 0, r = INT_MAX;
	while (l <= r) {
		long long mid = (l + r) / 2;
		long long ratio = 100 * (y + mid) / (x + mid);
		if (z < ratio) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << l << '\n';

	return 0;
}
