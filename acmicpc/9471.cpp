#include <iostream>
using namespace std;

int main()
{
	int t;

	cin >> t;
	while (t--) {
		int n, m;

		cin >> n >> m;
		int x = 0, y = 1, cnt = 0;
		while (1) {
			if (x == 0 && y == 1 && cnt != 0)
				break;

			int k = x;
			x = y;
			y = (k + x) % m;
			cnt++;
		}
		cout << n << ' ' << cnt << '\n';
	}

	return 0;
}
