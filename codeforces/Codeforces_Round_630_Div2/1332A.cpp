#include <iostream>
using namespace std;

int T, a, b, c, d, x, y, x1, y1, x2, y2;

int main()
{
	cin >> T;
	while (T--) {
		cin >> a >> b >> c >> d;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;

		bool flag = false;
		if ((x1 == x2 && a + b > 0) || (y1 == y2 && c + d > 0))
			flag = true;

		if (b > a) {
			if (b - a > x2 - x)
				flag = true;
		} else {
			if (a - b > x - x1)
				flag = true;
		}

		if (d > c) {
			if (d - c > y2 - y)
				flag = true;
		} else {
			if (c - d > y - y1)
				flag = true;
		}

		if (flag)
			cout << "No\n";
		else
			cout << "Yes\n";
	}

	return 0;
}
