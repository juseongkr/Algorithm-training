#include <iostream>
#include <cstring>
using namespace std;
#define MAX 51
#define MOD 1000000007

long long dp[MAX][MAX][MAX][MAX];
int n, a, b, c;

int solve(int cur, int a, int b, int c)
{
	if (cur == n) {
		if (a == 0 && b == 0 && c == 0)
			return 1;
		return 0;
	}

	if (dp[cur][a][b][c] != -1)
		return dp[cur][a][b][c];

	dp[cur][a][b][c] = 0;
	for (int i=0; i<2; ++i)
		for (int j=0; j<2; ++j)
			for (int k=0; k<2; ++k)
				if (i+j+k != 0)
					dp[cur][a][b][c] += solve(cur+1, a-i, b-j, c-k);
	dp[cur][a][b][c] %= MOD;
	return dp[cur][a][b][c];
}

int main()
{
	cin >> n >> a >> b >> c;

	memset(dp, -1, sizeof(dp));
	cout << solve(0, a, b, c) << '\n';

	return 0;
}
