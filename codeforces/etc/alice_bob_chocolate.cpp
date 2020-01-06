#include <stdio.h>

int main()
{
	int num, l, r, left_sum = 0, right_sum = 0;
	int chocolate[100000];

	scanf("%d", &num);

	for (int i=0; i<num; ++i) {
		scanf("%d", &chocolate[i]);
	}
	l = 0;
	r = num-1;
	
	while (l <= r) {
		if (left_sum <= right_sum)
			left_sum += chocolate[l++];
		else
			right_sum += chocolate[r--];
	}

	printf("%d %d\n", l, num-1-r);

	return 0;
}
