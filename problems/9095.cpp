#include <iostream>
using namespace std;

int dp[11];

int main()
{
	int num, n;

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	for (int i=3; i<=10; ++i)
		for (int j=1; j<=3; ++j)
			dp[i] += dp[i-j];
	
	cin >> num;

	for (int i=0; i<num; ++i) {
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}
