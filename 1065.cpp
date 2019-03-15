#include <stdio.h>

int main()
{
	int num, cnt = 0;
	int n1, n2, n3;

	scanf("%d", &num);

	if (num < 100) {
		printf("%d\n", num);
	} else {
		for (int i=100; i<=num; i++) {
			n1 = i / 100;
			n2 = (i / 10) % 10;
			n3 = i % 10;
			
			if ((n1 - n2) == (n2 - n3))
				cnt++;
		}
		printf("%d\n", cnt + 99);
	}

	return 0;
}

