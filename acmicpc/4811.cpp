#include <iostream>
#include <cstring>
using namespace std;
#define MAX 31

long long dp[MAX][MAX];

long long solve(int a, int b)
{
	if (a == 0)
		return 1;

	if (dp[a][b] != -1)
		return dp[a][b];

	dp[a][b] = solve(a-1, b+1);
	if (b > 0)
		dp[a][b] += solve(a, b-1);

	return dp[a][b];
}

int main()
{
	int n;

	while (cin >> n) {
		if (n == 0)
			break;

		memset(dp, -1, sizeof(dp));
		cout << solve(n, 0) << '\n';
	}

	return 0;
}
