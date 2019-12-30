#include <iostream>
#include <cstring>
using namespace std;
const int INF = 1e9+7;
#define MAX 101

int n, h;
int w[MAX], c[MAX];
int dp[MAX][50001];

int solve(int cur, int wei)
{
	if (cur == n)
		return INF;
	if (wei <= 0)
		return 0;

	if (dp[cur][wei] != -1)
		return dp[cur][wei];
	
	dp[cur][wei] = min(solve(cur+1, wei), solve(cur, wei - w[cur]) + c[cur]);

	return dp[cur][wei];
}

int main()
{
	cin >> n >> h;
	for (int i=0; i<n; ++i)
		cin >> w[i] >> c[i];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, h) << '\n';

	return 0;
}
