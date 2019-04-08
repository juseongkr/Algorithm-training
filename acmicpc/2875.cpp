#include <iostream>
using namespace std;

int main()
{
	int n, m, k, v;

	scanf("%d %d %d", &n, &m, &k);

	v = min(n/2, (n+m-k)/3);
	v = min(v, m);

	printf("%d\n", v);

	return 0;
}
