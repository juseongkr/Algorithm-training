#include <stdio.h>

int main()
{
	int num, backup, result, sum, cnt = 0;

	scanf("%d", &num);
	backup = num;

	while (1) {
		result = 0;
		sum = 0;
		result += (num % 10) * 10;
		while (num != 0) {
			sum += num % 10;
			num /= 10;
		}
		result += sum % 10;
		++cnt;

		if (backup == result) {
			printf("%d\n", cnt);
			break;
		}

		num = result;
	}

	return 0;
}

