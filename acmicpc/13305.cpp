#include <iostream>
using namespace std;

long long len[1000001];
long long cost, sum, min_cost = 1000000001;

int main()
{
	int n;

	scanf("%d", &n);
	for (int i=0; i<n-1; ++i)
		scanf("%lld", &len[i]);

	for (int i=0; i<n-1; ++i) {
		scanf("%lld", &cost);
		min_cost = min(min_cost, cost);
		sum += min_cost * len[i];
	}
	printf("%lld\n", sum);

	return 0;
}
