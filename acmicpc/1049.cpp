#include <iostream>
using namespace std;

#define MAX 1001

int main()
{
	int n, m, a, b;

	int x = MAX, y = MAX;
	scanf("%d %d", &n, &m);
	for (int i=0; i<m; ++i) {
		scanf("%d %d", &a, &b);
		x = min(x, a);
		y = min(y, b);
	}

	if (x > 6 * y)
		x = 6 * y;
	
	if (x < (n % 6) * y)
		printf("%d\n", (n/6) * x + x);
	else
		printf("%d\n", (n/6) * x + (n%6) * y);

	return 0;
}
