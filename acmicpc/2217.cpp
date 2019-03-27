#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int r[100001], n;
	long long ans = 0;

	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d", &r[i]);

	sort(r, r + n, cmp);

	for (int i=0; i<n; ++i) {
		if (r[i] * (i+1) > ans)
			ans = r[i] * (i+1);
	}

	printf("%lld\n", ans);

	return 0;
}
