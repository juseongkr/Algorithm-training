#include <iostream>
using namespace std;

int main()
{
	int coin[6] = {500, 100, 50, 10, 5, 1};
	int n, cnt = 0;

	scanf("%d", &n);
	n = 1000 - n;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<6; ++j) {
			if (n >= coin[j]) {
				cnt += n / coin[j];
				n %= coin[j];
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}
