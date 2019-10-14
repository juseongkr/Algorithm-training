#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101

long long dp[11][MAX][MAX][MAX];
long long c[11][11];

long long solve(int n, int r, int g, int b)
{
	if (r < 0 || g < 0 || b < 0)
		return 0;

	if (n == 0)
		return 1;

	long long &ref = dp[n][r][g][b];
	if (ref != -1)
		return ref;

	ref = 0;
	ref += solve(n-1, r-n, g, b) + solve(n-1, r, g-n, b) + solve(n-1, r, g, b-n);
	if (n % 2 == 0) {
		ref += solve(n-1, r-n/2, g-n/2, b) * c[n][n/2];
		ref += solve(n-1, r, g-n/2, b-n/2) * c[n][n/2];
		ref += solve(n-1, r-n/2, g, b-n/2) * c[n][n/2];
	}

	if (n % 3 == 0)
		ref += solve(n-1, r-n/3, g-n/3, b-n/3) * c[n][n/3] * c[n-n/3][n/3];

	return ref;
}

int main()
{
	int n, r, g, b;

	cin >> n >> r >> g >> b;
	c[0][0] = 1;
	for (int i=1; i<=10; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j=1; j<i; ++j)
			c[i][j] = c[i-1][j-1] + c[i-1][j];
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(n, r, g, b) << '\n';

	return 0;
}
