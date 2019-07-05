#include <iostream>
using namespace std;
#define MAX 100001

int main()
{
	int dp[MAX];
	int n;

	cin >> n;
	for (int i=1; i<=n; ++i) {
		dp[i] = i;
		for (int j=1; j*j<=i; ++j)
			dp[i] = min(dp[i], dp[i-j*j] + 1);
	}
	cout << dp[n] << '\n';

	return 0;
}
