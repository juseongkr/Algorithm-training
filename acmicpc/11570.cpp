#include <iostream>
#include <cstring>
using namespace std;
#define MAX 2001
const int INF = 1e9+7;

int n;
int val[MAX], dp[MAX][MAX];

int solve(int x, int y)
{
	if (x == n || y == n)
		return 0;

	if (~dp[x][y])
		return dp[x][y];

	int z = max(x, y);
	dp[x][y] = INF;
	dp[x][y] = min(dp[x][y], solve(x, z+1) + (y ? abs(val[y-1]-val[z]) : 0));
	dp[x][y] = min(dp[x][y], solve(z+1, y) + (x ? abs(val[x-1]-val[z]) : 0));

	return dp[x][y];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> val[i];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';

	return 0;
}
