#include <stdio.h>

int main()
{
	int input[8];
	char flag = 0;

	for (int i=0; i<8; ++i)
		scanf("%d", &input[i]);

	for (int i=0; i<7; ++i) {
		if (input[i] < input[i+1])
			flag++;
		else
			flag--;
	}

	if (flag == 7)
		printf("ascending\n");
	else if (flag == -7)
		printf("descending\n");
	else
		printf("mixed\n");

	return 0;
}
