#include <cstdio>
#include <cmath>
using namespace std;
#define EPSLION 1e-9

int a, b, c;

int main()
{
	scanf("%d %d %d", &a, &b, &c);
	double l = 0, r = 1.0*a*c + a;
	while (r-l >= EPSLION) {
		double x = (l+r)/2;
		if (a * x + b * sin(x) < c)
			l = x;
		else
			r = x;
	}

	printf("%.15lf\n", r);

	return 0;
}
