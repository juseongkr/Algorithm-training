#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 1001
const double INF = 1e9;

int n, t;
int d[MAX], s[MAX];
double l = -INF, r = INF;

double check(double mid)
{
	double ret = 0;
	for (int i=0; i<n; ++i) {
		ret += d[i] / (s[i] + mid);
		if (ret > t)
			break;
	}
	return ret < t;
}

int main()
{
	cin >> n >> t;
	for (int i=0; i<n; ++i) {
		cin >> d[i] >> s[i];
		l = max(l, s[i] * -1.0);
	}

	while (r - l > 1e-8) {
		double mid = (l+r)/2.0;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	cout << fixed << setprecision(10) << (l+r)/2 << '\n';

	return 0;
}
