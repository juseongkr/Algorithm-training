#include <iostream>
using namespace std;

int main()
{
	int n, k, cnt = 0;
	bool check[1001];

	scanf("%d %d", &n, &k);
	for (int i=2; i<=n; ++i)
		check[i] = true;

	for (int i=2; i<=n; ++i) {
		for (int j=i; j<=n; j+=i) {
			if (!check[j])
				continue;
			check[j] = false;
			if (++cnt == k) {
				printf("%d\n", j);
				break;
			}
		}
	}

	return 0;
}
