#include <iostream>
using namespace std;

const int mod = 1000000000;

int main()
{
	int dp[101][10];
	int num, sum = 0;

	scanf("%d", &num);
	dp[0][0] = 0;
	for (int i=1; i<10; ++i)
		dp[0][i] = 1;

	for (int i=1; i<num; ++i) {
		for (int j=0; j<10; ++j) {
			if (j == 0)
				dp[i][j] = dp[i-1][1];
			else if (j == 9)
				dp[i][j] = dp[i-1][8];
			else
				dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % mod;
		}
	}

	for (int i=0; i<10; ++i)
		sum = (sum + dp[num-1][i]) % mod;

	printf("%d\n", sum);

	return 0;
}
