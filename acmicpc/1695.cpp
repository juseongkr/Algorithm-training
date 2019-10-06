#include <iostream>
#include <cstring>
using namespace std;
#define MAX 5001

int n;
int num[MAX];
int dp[MAX][MAX];

int solve(int l, int r)
{
	if (l > r)
		return 0;

	if (dp[l][r] != -1)
		return dp[l][r];

	if (num[l] == num[r])
		return dp[l][r] = solve(l+1, r-1);

	return dp[l][r] = min(solve(l+1, r) + 1, solve(l, r-1) + 1);
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, n-1) << '\n';

	return 0;
}
