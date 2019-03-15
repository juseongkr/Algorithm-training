#include <stdio.h>

int main()
{
	int cnt[10] = {0,};
	int a, b, c;
	int num;

	scanf("%d %d %d", &a, &b, &c);

	num = a * b * c;

	while (num != 0) {
		cnt[num % 10]++;
		num /= 10;
	}

	for (int i=0; i<10; ++i)
		printf("%d\n", cnt[i]);

	return 0;
}
