#include <stdio.h>

int main()
{
	int score;

	scanf("%d", &score);

	if (90 <= score && score <= 100)
		printf("A\n");
	else if (80 <= score && score <= 89)
		printf("B\n");
	else if (70 <= score && score <= 79)
		printf("C\n");
	else if (60 <= score && score <= 69)
		printf("D\n");
	else
		printf("F\n");

	return 0;
}
