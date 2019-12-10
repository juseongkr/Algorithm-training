#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001

int n;
int dp[MAX][MAX];
int a[MAX], b[MAX];

int solve(int l, int r)
{
	if (l == n || r == n)
		return 0;

	if (dp[l][r] != -1)
		return dp[l][r];

	dp[l][r] = max(solve(l+1, r), solve(l, r+1));
	if (abs(a[l] - b[r]) <= 4)
		dp[l][r] = max(dp[l][r], solve(l+1, r+1) + 1);

	return dp[l][r];
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];

	for (int i=0; i<n; ++i)
		cin >> b[i];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';

	return 0;
}
