#include <iostream>
using namespace std;

int coin[11] = {0, };

int main()
{
	int n, k, cnt = 0;

	scanf("%d %d", &n, &k);

	for (int i=1; i<=n; ++i)
		scanf("%d", &coin[i]);
	
	for (int i=n; i>0; i--) {
		cnt += k / coin[i];
		k %= coin[i];
	}

	printf("%d", cnt);

	return 0;
}
