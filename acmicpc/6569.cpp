#include <iostream>
#include <cstring>
using namespace std;
#define MAX 11
#define ll long long

int h, w;
ll dp[MAX][MAX][(1 << MAX)];

ll solve(int n, int m, int bit)
{
	if (n == h)
		return bit == 0;
	if (m == w)
		return solve(n+1, 0, bit);

	if (~dp[n][m][bit])
		return dp[n][m][bit];

	if (bit & (1 << m))
		return solve(n, m+1, bit & ~(1 << m));

	dp[n][m][bit] = solve(n, m+1, bit | (1 << m));
	if (m+2 <= w && !(bit & (2 << m)))
		dp[n][m][bit] += solve(n, m+2, bit);

	return dp[n][m][bit];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	while (1) {
		cin >> h >> w;
		if (h == 0 && w == 0)
			break;

		if (h*w % 2) {
			cout << "0\n";
		} else {
			memset(dp, -1, sizeof(dp));
			cout << solve(0, 0, 0) << '\n';
		}
	}

	return 0;
}
