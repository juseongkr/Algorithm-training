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
	for (int i=l; i<r; ++i) {
		int left = solve(l, i);
		int right = solve(i+1, r);
		if (left != 0 && left == right)
			dp[l][r] = max(dp[l][r], left + 1);
	}

	return dp[l][r];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

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
