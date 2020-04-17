#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101
#define ll long long
const ll INF = 1e18+7;

int T, n, s, k;
ll psum[MAX], dp[MAX][MAX][2];

ll solve(int l, int r, bool w)
{
	if (l == 1 && r == n)
		return 0;

	if (~dp[l][r][w])
		return dp[l][r][w];

	ll left = n-r+l-1;
	dp[l][r][w] = INF;
	if (1 < l)
		dp[l][r][w] = min(dp[l][r][w], solve(l-1, r, 0) + left * (psum[w ? r : l] - psum[l-1]));
	if (r < n)
		dp[l][r][w] = min(dp[l][r][w], solve(l, r+1, 1) + left * (psum[r+1] - psum[w ? r : l]));

	return dp[l][r][w];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> s;
		fill(psum, psum+MAX, 0);
		for (int i=2; i<=n; ++i) {
			cin >> psum[i];
			psum[i] += psum[i-1];
		}

		memset(dp, -1, sizeof(dp));
		cout << min(solve(s, s, 0), solve(s, s, 1)) << '\n';
	}

	return 0;
}
