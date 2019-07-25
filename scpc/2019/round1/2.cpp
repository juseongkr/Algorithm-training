#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define MAX 1000001

int main()
{
	int t, n;
	double r, s, e, a, b, h;

	cin >> t;
	for (int c=1; c<=t; ++c) {
		cin >> r >> s >> e;

		cin >> n;
		double sum = 0;
		for (int i=0; i<n; ++i) {
			cin >> a >> b >> h;
			double k = sqrt(r*r - (r-h)*(r-h));
			if (r > h) {
				double theta = acos(k/r) * 180 / M_PI;
				double ret = (2 * r * M_PI) * (90-theta)/360;
				sum += (a - k - s);
				sum += (b - a);
				sum += ret * 2;
				s = b + k;
			} else {
				sum += (a - r - s);
				sum += (h - r) * 2;
				sum += (b - a);
				sum += r * M_PI;
				s = b + r;
			}
		}
		sum += e - s;

		cout << fixed << setprecision(9);
		cout << "Case #" << c << '\n' << sum << '\n';
	}

	return 0;
}
