#include <iostream>
using namespace std;

int main()
{
	double num;
	int n;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%lf", &num);
		printf("$%.2lf\n", num-(num*0.2));
	}

	return 0;
}
