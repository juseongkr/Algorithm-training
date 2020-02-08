#include <iostream>
using namespace std;

int t, a, b, c;

int main()
{
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		int ans = 0;

		int x = min(b, c/2);
		b -= x;
		int y = min(a, b/2);

		cout << (x + y) * 3 << '\n';
	}

	return 0;
}

