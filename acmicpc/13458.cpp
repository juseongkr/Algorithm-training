#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int num[1000001];
	int n, a, b;
	long long ans;
	
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d", &num[i]);

	ans = n;
	scanf("%d %d", &a, &b);
	for (int i=0; i<n; ++i) {
		num[i] -= a;
		if (num[i] > 0)
			ans += ceil(num[i] / (double)b);
	}

	printf("%lld\n", ans);

	return 0;
}
