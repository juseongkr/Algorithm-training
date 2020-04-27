#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 1001
const int INF = 1e9+7;

vector<int> vec;
int dp[MAX][MAX][2];
int n, l, t;

int solve(int l, int r, int d)
{
	if (l == 0 && r == n)
		return 0;

	if (l < 0 || r > n)
		return INF;

	if (dp[l][r][d] != -1)
		return dp[l][r][d];

	int x = n - (r - l);
	dp[l][r][d] = INF;
	if (d)
		dp[l][r][d] = min(solve(l-1, r, 0) + abs(vec[r] - vec[l-1]) * x, \
				solve(l, r+1, 1) + abs(vec[r] - vec[r+1]) * x);
	else
		dp[l][r][d] = min(solve(l-1, r, 0) + abs(vec[l] - vec[l-1]) * x, \
				solve(l, r+1, 1) + abs(vec[l] - vec[r+1]) * x);

	return dp[l][r][d];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> l;
	vec.push_back(l);
	for (int i=0; i<n; ++i) {
		cin >> t;
		vec.push_back(t);
	}

	sort(vec.begin(), vec.end());

	int ans = 0;
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<n+1; ++i) {
		if (vec[i] == l) {
			ans = solve(i, i, 0);
			break;
		}
	}
	cout << ans << '\n';

	return 0;
}
