#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int num, max_val = 0;
	int house[100000] = {0, };
	int result[100000] = {0, };

	scanf("%d", &num);

	for (int i=0; i<num; ++i)
		scanf("%d", &house[i]);

	for (int i=num-1; i>=0; --i) {
		if (house[i] > max_val)
			max_val = house[i];
		else
			result[i] = max_val - house[i] + 1;
	}
	
	for (int i=0; i<num; ++i)
		printf("%d ", result[i]);
	printf("\n");

	return 0;
}
