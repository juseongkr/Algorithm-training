#include <iostream>
#include <cstring>
using namespace std;
#define MAX 501

int n;
int map[MAX][MAX], dp[MAX][MAX];

int solve(int a, int b)
{
	if (a == n-1)
		return map[a][b];

	if (dp[a][b] != -1)
		return dp[a][b];

	dp[a][b] = max(solve(a+1, b), solve(a+1, b+1)) + map[a][b];
	return dp[a][b];
}

int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<n; ++i)
		for (int j=0; j<=i; ++j)
			cin >> map[i][j];

	cout << solve(0, 0) << '\n';

	return 0;
}
