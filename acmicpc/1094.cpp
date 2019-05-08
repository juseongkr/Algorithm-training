#include <iostream>
using namespace std;

int main()
{
	int n, cnt = 0;

	scanf("%d", &n);
	while (n) {
		if (n%2 == 1)
			cnt++;
		n /= 2;
	}

	printf("%d\n", cnt);

	return 0;
}
