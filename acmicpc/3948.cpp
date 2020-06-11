#include <iostream>
#include <cstring>
using namespace std;
#define MAX 21

int t, n;
long long dp[MAX];
long long c[MAX][MAX];

void combination()
{
	c[0][0] = 1;
	for (int i=1; i<MAX; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j=1; j<i; ++j)
			c[i][j] = c[i-1][j-1] + c[i-1][j];
	}
}

long long solve(int n)
{
	if (n <= 2)
		return 1;

	if (~dp[n])
		return dp[n];

	dp[n] = 0;
	for (int i=1; i<=n; i+=2)
		dp[n] += solve(i-1) * solve(n-i) * c[n-1][i-1];

	return dp[n];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	combination();
	while (t--) {
		cin >> n;
		memset(dp, -1, sizeof(dp));
		if (n == 1)
			cout << "1\n";
		else
			cout << solve(n) * 2 << '\n';
	}

	return 0;
}
