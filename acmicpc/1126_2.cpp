#include <iostream>
#include <cstring>
using namespace std;
#define MAX 51
const int INF = 1e9+7;

int n;
int num[MAX];
int dp[MAX][250001];

int solve(int i, int d)
{
	if (d > 250000)
		return -INF;

	if (i == n) {
		if (d == 0)
			return 0;
		else
			return -INF;
	}

	if (dp[i][d] != -1)
		return dp[i][d];

	dp[i][d] = max(solve(i+1, d), solve(i+1, d + num[i]));
	if (d < num[i])
		dp[i][d] = max(dp[i][d], solve(i+1, num[i] - d) + d);
	else
		dp[i][d] = max(dp[i][d], solve(i+1, d - num[i]) + num[i]);

	return dp[i][d];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	memset(dp, -1, sizeof(dp));

	int ans = solve(0, 0);
	if (ans == 0)
		cout << "-1\n";
	else
		cout << ans << '\n';

	return 0;
}
