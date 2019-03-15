#include <iostream>
using namespace std;
int dp[10001], wine[10001];

int main()
{
	int num;

	cin >> num;

	for (int i=1; i<=num; ++i)
		cin >> wine[i];

	dp[1] = wine[1];
	dp[2] = dp[1] + wine[2];

	for (int i=3; i<=num; ++i) {
		dp[i] = max(dp[i-2] + wine[i], dp[i-3] + wine[i-1] + wine[i]);
		dp[i] = max(dp[i-1], dp[i]);
	}
	
	cout << dp[num] << '\n';
	
	return 0;
}
