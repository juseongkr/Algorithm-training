#include <iostream>
using namespace std;

long long dp[70] = {0, };

long long koong(int n)
{
	if (n < 2)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 4;
	if (dp[n] != 0)
		return dp[n];

	dp[n] = koong(n-1) + koong(n-2) + koong(n-3) + koong(n-4);

	return dp[n];
}

int main()
{
	int num, n;

	scanf("%d", &num);

	for (int i=0; i<num; ++i) {
		scanf("%d", &n);
		printf("%lld\n", koong(n));
	}

	return 0;
}
