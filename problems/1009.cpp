#include <iostream>
using namespace std;

int main()
{
	int num, a, b, res;

	scanf("%d", &num);

	for (int i=0; i<num; ++i) {
		scanf("%d %d", &a, &b);
		res = 1;

		for (int j=0; j<b; ++j)
			res = (res * a) % 10;
		if (res == 0)
			res = 10;

		printf("%d\n", res);
	}

	return 0;
}
