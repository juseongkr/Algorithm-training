#include <stdio.h>
#include <algorithm>

bool compare(int a, int b) { return a > b; };

int main()
{
	int num, val, imp, sum = 0;
	int skill[100000];

	scanf("%d %d", &num, &imp);

	for (int i=0; i<num; ++i) {
		scanf("%d", &val);
		sum += val / 10;
		skill[i] = val % 10;
	}

	std::sort(skill, skill + num, compare);

	for (int i=0; i<num; ++i) {
		if (imp >= (10 - skill[i])) {
			imp -= (10 - skill[i]);
			sum++;
		} else {
			break;
		}
	}

	if (imp >= 10)
		sum += (imp / 10);
	if (sum > (10 * num))
		sum = 10 * num;

	printf("%d\n", sum);
		
	return 0;
}
