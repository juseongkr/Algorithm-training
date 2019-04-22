#include <iostream>
using namespace std;

int main()
{
	int n;

	scanf("%d", &n);
	for (int i=1; i<n; ++i) {
		for (int j=1; j<=n; ++j) {
			if (j > n-i)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

	for (int i=n; i>0; i--) {
		for (int j=1; j<=n; ++j) {
			if (j > n-i)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}
