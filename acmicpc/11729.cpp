#include <iostream>
using namespace std;

void hanoi(int a, int b, int c, int n)
{
	if (n == 1) {
		printf("%d %d\n", a, c);
		return;
	}
	hanoi(a, c, b, n-1);
	printf("%d %d\n", a, c);
	hanoi(b, a, c, n-1);
}

int main()
{
	int n;

	scanf("%d", &n);
	printf("%d\n", (1<<n)-1);
	hanoi(1, 2, 3, n);

	return 0;
}
