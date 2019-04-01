#include <iostream>
using namespace std;

long long sum[1000001];
long long cnt[1001];

int main()
{
	int n, m, t;
	long long ret = 0;
	
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i) {
		scanf("%d", &t);

		sum[i+1] = (sum[i] + t) % m;
		
		if (sum[i+1] == 0)
			ret++;

		cnt[sum[i+1]] += 1;
	}

	for (int i=0; i<m; ++i)
		ret += cnt[i] * (cnt[i] - 1) / 2;
	
	printf("%lld\n", ret);

	return 0;
}
