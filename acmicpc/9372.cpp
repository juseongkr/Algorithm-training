#include <iostream>
using namespace std;

int main()
{
	int t, n, m, a, b;

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i=0; i<m; ++i)
			scanf("%d %d", &a, &b);

		printf("%d\n", n-1);
	}
	return 0;
}
