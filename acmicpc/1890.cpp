#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101

int n;
int map[MAX][MAX];
long long dp[MAX][MAX];

long long solve(int y, int x)
{
	if (y == n-1 && x == n-1)
		return 1;

	if (dp[y][x] != -1)
		return dp[y][x];

	dp[y][x] = 0;
	if (map[y][x] + y < n)
		dp[y][x] += solve(map[y][x] + y, x);

	if (map[y][x] + x < n)
		dp[y][x] += solve(y, map[y][x] + x);

	return dp[y][x];
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cin >> map[i][j];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';

	return 0;
}
