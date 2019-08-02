#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001

int n, m;
int num[MAX];
int dp[MAX][MAX];

int solve(int cur, int fill)
{
	if (cur == n)
		return 0;

	if (dp[cur][fill] != -1)
		return dp[cur][fill];

	dp[cur][fill] = solve(cur+1, num[cur]+1) + (m-fill+1) * (m-fill+1);
	if (fill + num[cur] <= m)
		dp[cur][fill] = min(dp[cur][fill], solve(cur+1, fill+num[cur]+1));

	return dp[cur][fill];
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';

	return 0;
}
