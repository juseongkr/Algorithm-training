#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll long long

int n, L, W, H;

int main()
{
	scanf("%d %d %d %d", &n, &L, &W, &H);
	long double l = 0, r = max({L, W, H});
	for (int i=0; i<10000; ++i) {
		long double mid = (l+r)/2;
		if (((ll)(L / mid) * (ll)(W / mid) * (ll)(H / mid)) >= n)
			l = mid;
		else
			r = mid;
	}
	printf("%.10Lf\n", l);

	return 0;
}
