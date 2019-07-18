#include <iostream>
using namespace std;

int main()
{
	int num[6];
	int k, d, l, p, q, x = 0, y = 0;

	cin >> k;
	for (int i=0; i<6; ++i) {
		cin >> d >> num[i];
		if (i % 2 == 0)
			x = max(x, num[i]);
		else
			y = max(y, num[i]);
	}

	for (int i=0; i<6; ++i) {
		if (i % 2 == 0) {
			if (y == num[(i+5)%6] + num[(i+1)%6])
				q = num[i];
		} else {
			if (x == num[(i+5)%6] + num[(i+1)%6])
				p = num[i];
		}
	}

	cout << ((x * y) - (p * q)) * k << '\n';

	return 0;
}
