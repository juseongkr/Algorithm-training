#include <iostream>
using namespace std;

#define MOD 10007
int dp[1001][10];

int main()
{
	int n, sum = 0;

	scanf("%d", &n);
	for (int i=0; i<10; ++i)
		dp[0][i] = 1;

	for (int i=1; i<n; ++i)
		for (int j=1; j<10; ++j)
			for (int k=j; k<10; ++k)
				dp[i][j] += (dp[i-1][k] % MOD);

	for (int i=0; i<n; ++i)
		for (int j=0; j<10; ++j)
			sum += dp[i][j];

	printf("%d\n", sum % MOD);

	return 0;
}
