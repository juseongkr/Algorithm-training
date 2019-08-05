#include <iostream>
using namespace std;
#define ll long long
#define MAX 1000001
#define MOD 1000000000

ll dp[MAX];

int main()
{
	int n, m;

	cin >> n;
	m = n;
	if (n < 0)
		m *= -1;

	dp[1] = 1;
	for (int i=2; i<=m; ++i) {
		dp[i] = dp[i-1] + dp[i-2];
		dp[i] %= MOD;
	}

	if (n == 0) {
		cout << "0\n0";
	} else if (n > 0) {
		cout << "1\n" << dp[m] << '\n';
	} else {
		if (m % 2 == 0)
			cout << "-1\n" << dp[m] << '\n';
		else
			cout << "1\n" << dp[m] << '\n';
	}

	return 0;
}
