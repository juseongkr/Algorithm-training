#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double dist(double x1, double y1, double z1, double x2, double y2, double z2)
{
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));
}

int main()
{
	int x1, y1, z1, x2, y2, z2, x3, y3, z3;

	cin >> x1 >> y1 >> z1;
	cin >> x2 >> y2 >> z2;
	cin >> x3 >> y3 >> z3;
	double l = 0.0, r = 1.0, mid = 0.0;
	while (1) {
		if (abs(r-l) < 1e-9) {
			mid = (l+r)/2;
			break;
		}
		double m1 = l + (r-l)/3;
		double m2 = r - (r-l)/3;

		double m1_x = x1 + m1 * (x2-x1);
		double m1_y = y1 + m1 * (y2-y1);
		double m1_z = z1 + m1 * (z2-z1);

		double m2_x = x1 + m2 * (x2-x1);
		double m2_y = y1 + m2 * (y2-y1);
		double m2_z = z1 + m2 * (z2-z1);

		double d1 = dist(m1_x, m1_y, m1_z, x3, y3, z3);
		double d2 = dist(m2_x, m2_y, m2_z, x3, y3, z3);

		if (d1 > d2)
			l = m1;
		else
			r = m2;
	}

	double x = x1 + mid * (x2-x1);
	double y = y1 + mid * (y2-y1);
	double z = z1 + mid * (z2-z1);

	cout << fixed << setprecision(10) << dist(x, y, z, x3, y3, z3) << '\n';

	return 0;
}
