#include <iostream>
using namespace std;

int main()
{
	int a, b, c, x, y;

	cin >> a >> b >> c >> x >> y;
	int ans = a*x + b*y;
	for (int i=0; i<max(x, y)*2; ++i) {
		ans = min(ans, 2 * i * c + max(0, x-i) * a + max(0, y-i) * b);
	}
	cout << ans << '\n';

	return 0;
}
