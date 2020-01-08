#include <iostream>
using namespace std;

int a, b, c, d, e, f, ans;

int main()
{
	cin >> a >> b >> c >> d >> e >> f;
	if (e < f) {
		int y = min(b, min(c, d));
		ans += y * f;
		ans += min(a, d-y) * e;
	} else {
		int y = min(a, d);
		ans += y * e;
		ans += min(b, min(c, d-y)) * f;
	}

	cout << ans << '\n';

	return 0;
}
