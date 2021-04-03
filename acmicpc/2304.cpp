#include <iostream>
using namespace std;
#define MAX 1001

int block[MAX];
int x, y, n, l, r;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	int ans = 0;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		block[x] = y;
		r = max(r, x);
		ans += y;
	}

	int left_max = 0, right_max = 0;
	while (l < r) {
		if (block[l] < block[r]) {
			if (left_max <= block[l])
				left_max = block[l];
			else
				ans += left_max - block[l];
			l++;
		} else {
			if (right_max <= block[r])
				right_max = block[r];
			else
				ans += right_max - block[r];
			r--;
		}
	}

	cout << ans << '\n';

	return 0;
}
