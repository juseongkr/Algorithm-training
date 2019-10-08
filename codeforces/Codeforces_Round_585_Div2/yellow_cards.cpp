#include <iostream>
using namespace std;

int main()
{
	int a, b, x, y, z;

	cin >> a >> b >> x >> y >> z;
	if (x > y) {
		swap(x, y);
		swap(a, b);
	}
	int mi = (x-1) * a + (y-1) * b;
	cout <<  max(0, z - mi) << " ";
	
	int ans = 0;
	ans += z / x;
	ans = min(ans, a);
	z -= ans * x;
	ans += z / y;

	cout << ans << '\n';

	return 0;
}
