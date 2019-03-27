#include <stdio.h>

int main()
{
	int day, min_val, max_val, sumTime, total_max = 0, total_min = 0;
	int minTime[31], sub[31], result[31];

	scanf("%d %d", &day, &sumTime);

	for (int i=0; i<day; ++i) {
		scanf("%d %d", &min_val, &max_val);
		result[i] = min_val;
		sub[i] = max_val - min_val;
		total_max += max_val;
		total_min += min_val;
	}

	if (total_max < sumTime || sumTime < total_min) {
		printf("NO\n");
		return 0;
	}

	for (int i=0; i<day; ++i)
		sumTime -= result[i];
	
	for (int i=0; i<day; ++i) {
		if (sumTime == sub[i]) {
			result[i] += sumTime;
			printf("YES\n");
			break;
		} else if (sumTime > sub[i]) {
			result[i] += sub[i];
			sumTime -= sub[i];
		} else {
			result[i] += sumTime;
			printf("YES\n");
			break;
		}
	}

	for (int i=0; i<day; ++i)
		printf("%d ", result[i]);
	printf("\n");

	return 0;
}
