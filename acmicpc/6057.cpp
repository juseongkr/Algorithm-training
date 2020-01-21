#include <iostream>
using namespace std;
#define MAX 2501

long long dp[MAX];

int main()
{
	int n;

	cin >> n;
	dp[5] = 4;
	for (int i=6; i<MAX; ++i) {
		if (i % 2)
			dp[i] = dp[i-2] * (i+1) / (i-5);
		else
			dp[i] = dp[i-1] + (i-1) / 2;
	}
	cout << dp[n] << '\n';

	return 0;
}
