#include <stdio.h>

int main()
{
	int n;

	scanf("%d", &n);

	for (int i=1; i<=9; ++i)
		printf("%d * %d = %d\n", n, i, i*n);
	
	return 0;
}
