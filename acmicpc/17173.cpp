#include <iostream>
using namespace std;

int num[1001], dict[1001];

int main()
{
	long long ans = 0;
	int n, m;

	scanf("%d %d", &n, &m);
	for (int i=0; i<m; ++i)
		scanf("%d", &num[i]);

	for (int i=0; i<m; ++i) {
		long long sum = 0;
		for (int j=num[i]; j<=n; j=j+num[i]) {
			dict[j]++;
			if (dict[j] >= 2)
				continue;
			sum += j;
		}
		ans += sum;
	}
	printf("%lld\n", ans);

	return 0;
}
