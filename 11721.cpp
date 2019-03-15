#include <stdio.h>
#include <string.h>

int main()
{
	char str[100];
	int size;

	scanf("%s", str);
	size = strlen(str);

	for (int i=0; i<size; i++) {
		printf("%c", str[i]);

		if ((i+1) % 10 == 0)
			printf("\n");
	}

	return 0;
}
