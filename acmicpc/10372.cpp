#include <stdio.h>
using namespace std;

int digit[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n;

int main()
{
	scanf("%d", &n);
	for (int i=0; i<24; ++i) {
		for (int j=0; j<60; ++j) {
			if (digit[i%10] + digit[i/10] + digit[j%10] + digit[j/10] == n) {
				printf("%02d:%02d\n", i, j);
				return 0;
			}
		}
	}
	printf("Impossible\n");

	return 0;
}
