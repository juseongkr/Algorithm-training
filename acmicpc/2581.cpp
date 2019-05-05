#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> prime;
	bool check[10001];
	int m, n, ans = 0;

	scanf("%d %d", &m, &n);
	fill(check+2, check+n+1, true);
	for (int i=2; i<=n; ++i) {
		if (check[i] && i >= m)
			prime.push_back(i);
		for (int j=i; j<=n; j+=i)
			check[j] = false;
	}

	if (prime.size() == 0) {
		printf("-1\n");
	} else {
		for (int i=0; i<prime.size(); ++i)
			ans += prime[i];
		printf("%d\n%d\n", ans, prime[0]);
	}

	return 0;
}
