#include <iostream>
#include <cstring>
using namespace std;
#define MAX 2001

int n, m, x, y;
int num[MAX];
int dp[MAX][MAX];

int solve(int l, int r)
{
	if (l == r)
		return 1;

	if (dp[l][r])
		return dp[l][r];

	if (r - l == 1)
		return num[l] == num[r];

	if (num[l] == num[r])
		dp[l][r] = solve(l+1, r-1);

	return dp[l][r];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<=n; ++i)
		cin >> num[i];

	cin >> m;
	while (m--) {
		cin >> x >> y;
		cout << solve(x, y) << '\n';
	}

	return 0;
}
