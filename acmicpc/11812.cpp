#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n, x, y;
	int k, q;

	cin >> n >> k >> q;
	for (int i=0; i<q; ++i) {
		cin >> x >> y;
		if (k == 1) {
			cout << abs(x-y) << '\n';
		} else {
			int cnt = 0;
			while (x != y) {
				if (x < y)
					y = (y-2)/k+1;
				else
					x = (x-2)/k+1;
				cnt++;
			}
			cout << cnt << '\n';
		}
	}

	return 0;
}
