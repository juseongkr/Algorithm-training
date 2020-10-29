#include <iostream>
#include <cstring>
using namespace std;
#define MAX 11
#define MOD (1 << n)
const int INF = 1e9+7;

int n, m;
int dp[MAX][MAX][(1 << MAX)];
string map[MAX];

int solve(int x, int y, int bit)
{
	if (x == n)
		return solve(0, y+1, bit);
	if (y == m)
		return 0;

	if (~dp[x][y][bit])
		return dp[x][y][bit];

	dp[x][y][bit] = INF;
	if (map[x][y] == '#') {
		dp[x][y][bit] = solve(x+1, y, (bit << 1) % MOD + 1);
	} else {
		dp[x][y][bit] = min(dp[x][y][bit], solve(x+1, y, (bit << 1) % MOD + 1) \
				+ (x == 0 || map[x-1][y] == '#' || !(bit & (1 << 0))));

		dp[x][y][bit] = min(dp[x][y][bit], solve(x+1, y, (bit << 1) % MOD) \
				+ (bit & (1 << (n-1)) ? 1 : 0));
	}

	return dp[x][y][bit];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> map[i];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0, (1 << n)-1) << '\n';

	return 0;
}
