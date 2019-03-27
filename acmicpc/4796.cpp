#include <iostream>
using namespace std;

int main()
{
	int l, p, v, t;
	int i = 1;

	while (scanf("%d %d %d", &l, &p, &v) && l != 0 && p != 0 && v!= 0) {
		if (v % p < l)
			t = (v / p * l) + (v % p);
		else
			t = (v / p * l) + l;

		printf("Case %d: %d\n", i++, t);
	}

	return 0;
}
