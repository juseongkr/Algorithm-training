#include <iostream>
using namespace std;

int main()
{
	int n;

	scanf("%d", &n);
	for (int i=1; i<n; ++i) {
		for (int j=1; j<i; ++j)
			printf(" ");
		for (int j=0; j<=2*(n-i); ++j)
			printf("*");
		printf("\n");
	}

	for (int i=0; i<n; ++i) {
		for (int j=1; j<n-i; ++j)
			printf(" ");
		for (int j=0; j<=2*i; ++j)
			printf("*");
		printf("\n");
	}

	return 0;
}
