#include <iostream>
#include <algorithm>
using namespace std;

int n[4];
int t, x1, x2, y1, y2;

int main()
{
	cin >> t;
	while (t--) {
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == y2)
			cout << x1 << " " << x2 << '\n';
		else
			cout << x1 << " " << y2 << '\n';
	}

	return 0;
}
