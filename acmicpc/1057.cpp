#include <iostream>
using namespace std;

int main()
{
	int n, a, b, cnt = 0;

	scanf("%d %d %d", &n, &a, &b);
	while (a != b) {
		a = (a+1)/2;
		b = (b+1)/2;
		cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}
