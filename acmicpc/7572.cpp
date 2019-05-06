#include <iostream>
using namespace std;

int main()
{
	int n;

	scanf("%d", &n);
	n += 387;
	printf("%c%d\n", ((n + 5) % 12)+'A', (n + 9) % 10);

	return 0;
}
