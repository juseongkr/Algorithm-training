#include <iostream>
using namespace std;

int main()
{
	int a, b, c, ans;

	cin >> a >> b >> c;
	ans = a ^ b;
	for (int i=1; i<c; ++i)
		ans ^= b;

	cout << ans << '\n';

	return 0;
}
