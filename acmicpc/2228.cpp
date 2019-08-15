#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101

int n, m;
int num[MAX];
int dp[MAX][MAX/2+1];

int solve(int n, int m)
{
	if (m == 0)
		return 0;
	if (n <= 0)
		return -3276800;

	if (dp[n][m] != -1)
		return dp[n][m];

	int sum = 0;
	dp[n][m] = solve(n-1, m);
	for (int i=n; i>0; i--) {
		sum += num[i];
		int ret = solve(i-2, m-1) + sum;
		dp[n][m] = max(dp[n][m], ret);
	}

	return dp[n][m];
}

int main()
{
	cin >> n >> m;
	for (int i=1; i<=n; ++i)
		cin >> num[i];

	memset(dp, -1, sizeof(dp));
	cout << solve(n, m) << '\n';

	return 0;
}
