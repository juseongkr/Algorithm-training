#include <iostream>
#include <cstring>
using namespace std;
#define MAX 250

int n, ans;
int num[MAX], dp[MAX][MAX];

int solve(int l, int r)
{
	if (l == r)
		return num[l];

	if (~dp[l][r])
		return dp[l][r];

	dp[l][r] = 0;
	for (int i=l; i<r; ++i)
		if (solve(l, i) == solve(i+1, r))
			dp[l][r] = max(dp[l][r], solve(l, i) + 1);

	return dp[l][r];
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	memset(dp, -1, sizeof(dp));
	for (int i=0; i<n; ++i)
		for (int j=i; j<n; ++j)
			ans = max(ans, solve(i, j));

	cout << ans << '\n';

	return 0;
}
