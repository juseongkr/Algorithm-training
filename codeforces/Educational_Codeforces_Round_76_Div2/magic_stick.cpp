#include <iostream>
using namespace std;

int main()
{
	int t, x, y;

	cin >> t;
	while (t--) {
		cin >> x >> y;
		if (x >= y || x > 3 || (x == 2 && y == 3))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
