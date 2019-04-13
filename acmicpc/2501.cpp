#include <iostream>
using namespace std;

int main()
{
	int p, k, ans = 0;

	scanf("%d %d", &p, &k);
	for (int i=1; i<=p; ++i) {
		if (p % i == 0)
			ans++;
		if (ans == k) {
			printf("%d\n", i);
			return 0;
		}
	}

	printf("0\n");

	return 0;
}
