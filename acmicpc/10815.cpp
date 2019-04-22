#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<long long, int> hash;
	long long t;
	int n, m;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%lld", &t);
		hash[t]++;
	}

	scanf("%d", &m);
	for (int i=0; i<m; ++i) {
		scanf("%lld", &t);
		printf("%d ", hash[t]);
	}

	return 0;
}
