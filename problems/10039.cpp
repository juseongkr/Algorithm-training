#include <stdio.h>

int main()
{
	int score[5] = {0,};
	int total = 0;

	for (int i=0; i<5; ++i)
		scanf("%d", &score[i]);

	for (int i=0; i<5; ++i) {
		if (score[i] < 40)
			total += 40;
		else
			total += score[i];
	}

	printf("%d\n", total / 5);

	return 0;
}
