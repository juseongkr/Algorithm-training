#include <iostream>
using namespace std;

int main()
{
	int l, p, t;

	scanf("%d %d", &l, &p);

	for (int i=0; i<5; ++i) {
		scanf("%d", &t);
		printf("%d ", t - l * p);
	}

	return 0;
}
