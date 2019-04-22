#include <iostream>
using namespace std;

void star(int x, int y)
{
	while (x != 0) {
		if (x % 3 == 1 && y % 3 == 1)  {
			printf(" ");
			return;
		}
		x/=3;
		y/=3;
	}
	printf("*");
}

int main()
{
	int n;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			star(i, j);
		}
		printf("\n");
	}

	return 0;
}
