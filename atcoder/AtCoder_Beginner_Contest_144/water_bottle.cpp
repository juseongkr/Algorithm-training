#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double a, b, x;

	cin >> a >> b >> x;
	double c = a * a;
	if (x * 2 > b * c) {
		double t = (b * c - x) / c * 2;
		cout << setprecision(15) << atan2(t, a) * 180 / M_PI << '\n';
	} else {
		double t = x * 2 / b / a;
		cout << setprecision(15) << 90 - atan2(t, b) * 180 / M_PI << '\n';
	}

	return 0;
}
