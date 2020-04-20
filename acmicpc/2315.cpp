#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001
#define ll long long
const ll INF = 1e18+7;

int n, m, w;
ll psum[MAX], pos[MAX];
ll dp[MAX][MAX][2];

ll solve(int l, int r, bool w)
{
	if (l == 1 && r == n)
		return 0;

	if (~dp[l][r][w])
		return dp[l][r][w];

	dp[l][r][w] = INF;
	ll left = psum[n] - psum[r] + psum[l-1];
	if (1 < l)
		dp[l][r][w] = min(dp[l][r][w], solve(l-1, r, 0) + left * (pos[w ? r : l] - pos[l-1]));
	if (r < n)
		dp[l][r][w] = min(dp[l][r][w], solve(l, r+1, 1) + left * (pos[r+1] - pos[w ? r : l]));

	return dp[l][r][w];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=1; i<=n; ++i) {
		cin >> pos[i] >> w;
		psum[i] += psum[i-1] + w;
	}

	memset(dp, -1, sizeof(dp));
	cout << min(solve(m, m, 0), solve(m, m, 1)) << '\n';

	return 0;
}
