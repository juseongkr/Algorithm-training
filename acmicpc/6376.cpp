#include <iostream>
using namespace std;

int main()
{
	long double E = 0;
	int k = 1;

	printf("n e\n- -----------\n");
	printf("0 1\n1 2\n2 2.5\n");
	for (int i=0; i<=9; ++i) {
		if (i)
			k *= i;
		E += 1 / (long double)k;
		if (i >= 3)
			printf("%d %.9Lf\n", i, E);
	}

	return 0;
}
