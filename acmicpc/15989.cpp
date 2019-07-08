#include <iostream>
using namespace std;
#define MAX 10001

int dp[MAX][2];

int main()
{
	int n, t;

	dp[2][0] = 1;
	for (int i=3; i<MAX; ++i) {
		dp[i][0] += dp[i-2][0] + 1;
		dp[i][1] += dp[i-3][0] + dp[i-3][1] + 1;
	}
	
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> t;
		cout << dp[t][0] + dp[t][1] + 1 << '\n';
	}

	return 0;
}
