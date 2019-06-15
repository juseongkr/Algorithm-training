#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c, d;

	while (1) {
		cin >> a >> b >> c >> d;
		if (a == 0 && b == 0 && c == 0 && d == 0)
			return 0;

		int cnt = 0;
		while (1) {
			if (a == b && b == c && c == d) {
				cout << cnt << '\n';
				break;
			}
			int x = abs(a-b);
			int y = abs(b-c);
			int r = abs(c-d);
			int z = abs(d-a);
			a = x;
			b = y;
			c = r;
			d = z;
			cnt++;
		}
	}

	return 0;
}
