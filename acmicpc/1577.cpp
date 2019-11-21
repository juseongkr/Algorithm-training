#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101

int n, m, k, a, b, c, d;
bool A[MAX][MAX], B[MAX][MAX];
long long dp[MAX][MAX];

long long solve(int x, int y)
{
	if (x == n && y == m)
		return 1;

	if (dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = 0;
	if (x < n && !A[x][y])
		dp[x][y] += solve(x+1, y);

	if (y < m && !B[x][y])
		dp[x][y] += solve(x, y+1);

	return dp[x][y];
}

int main()
{
	cin >> n >> m >> k;
	for (int i=0; i<k; ++i) {
		cin >> a >> b >> c >> d;
		if (a == c)
			B[a][min(b, d)] = 1;
		else
			A[min(a, c)][b] = 1;
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';

	return 0;
}
