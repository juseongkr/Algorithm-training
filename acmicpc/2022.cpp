#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double x, y, c;

	cin >> x >> y >> c;
	double l = 0, r = min(x, y);
	for (int i=0; i<10000; ++i) {
		double mid = (l + r) / 2.0;
		double h1 = sqrt(x*x - mid*mid);
		double h2 = sqrt(y*y - mid*mid);
		double h = (h1*h2) / (h1+h2);
		if (h > c)
			l = mid;
		else
			r = mid;
	}
	cout << fixed << setprecision(3) << l << '\n';

	return 0;
}
