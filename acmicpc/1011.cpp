#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int t, x, y;
	long long i, ret;

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &x, &y);
		i = 1;
		while (i*i <= (y-x))
			i++;
		i--;

		ret = ceil((double)((y-x)-(i*i))/i);

		printf("%lld\n", 2*i + ret - 1);
	}

	return 0;
}
