#include <stdio.h>

int main()
{
	int n;
	int i = 0;

	scanf("%d", &n);

	while (n > 0) {
		if (n % 5 == 0) {
			i++;
			n -= 5;
		} else if (n % 3 == 0) {
			i++;
			n -= 3;
		} else {
			i++;
			n -= 5;
		}
	}

	if (n < 0)
		printf("-1\n");
	else
		printf("%d\n", i);

	return 0;
}
