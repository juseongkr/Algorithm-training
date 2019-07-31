#include <iostream>
#include <cstring>
using namespace std;
#define MAX 501

int n;
int dp[MAX][MAX];
int x[MAX], y[MAX];

int solve(int a, int b)
{
	if (a == b)
		return 0;

	if (a+1 == b)
		return x[a] * y[a] * y[b];

	if (dp[a][b] != -1)
		return dp[a][b];

	dp[a][b] = 1e9+7;
	for (int k=a; k<b; ++k)
		dp[a][b] = min(dp[a][b], solve(a, k) + solve(k+1, b) + x[a] * y[k] * y[b]);
	return dp[a][b];
}

int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<n; ++i)
		cin >> x[i] >> y[i];

	cout << solve(0, n-1) << '\n';

	return 0;
}
