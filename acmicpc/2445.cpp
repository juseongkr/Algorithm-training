#include <iostream>
using namespace std;

int main()
{
	int n;

	scanf("%d", &n);
	for (int i=1; i<n; ++i) {
		for (int j=1; j<=n*2; ++j) {
			if (j <= i || j > 2*n-i)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

	for (int i=n; i>0; i--) {
		for (int j=1; j<=2*n; ++j) {
			if (j <= i || j > 2*n-i)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}
