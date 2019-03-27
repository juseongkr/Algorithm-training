#include <stdio.h>
using namespace std;

int main()
{
	int array[10001] = {0, };
	int num, n;

	scanf("%d", &num);
	for (int i=0; i<num; ++i) {
		scanf("%d", &n);
		array[n]++;
	}

	for (int i=1; i<=10000; ++i) {
		if (array[i]) {
			for (int j=0; j<array[i]; ++j)
				printf("%d\n", i);
		}
	}

	return 0;
}
