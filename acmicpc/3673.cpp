#include <iostream>
using namespace std;

long long visit[1000001];

int main()
{
	int t, d, n, num;

	scanf("%d", &t);
	while (t--) {
		long long ans = 0;
		int sum = 0;
		scanf("%d %d", &d, &n);
		fill(visit, visit+d, 0);

		for (int i=0; i<n; ++i) {
			scanf("%d", &num);
			sum = (sum + num) % d;
			visit[sum]++;
		}

		visit[0]++;
		for (int i=0; i<d; ++i)
			ans += visit[i] * (visit[i]-1)/2;

		printf("%lld\n", ans);
	}
	return 0;
}
