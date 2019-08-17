#include <iostream>
#include <cstring>
using namespace std;
#define MAX 15
#define MOD 9901

int n, m;
char dubu[MAX][MAX];
int dp[MAX*MAX][1<<MAX];
int score[6][6] = { {10, 8, 7, 5, 0, 1},
		    {8, 6, 4, 3, 0, 1},
		    {7, 4, 3, 2, 0, 1},
		    {5, 3, 2, 2, 0, 1},
		    {0, 0, 0, 0, 0, 0},
		    {1, 1, 1, 1, 0, 0} };

int sum(char x, char y)
{
	return score[x-'A'][y-'A'];
}

int solve(int cur, int bit)
{
	if (cur >= n*m)
		return 0;

	if (dp[cur][bit] != -1)
		return dp[cur][bit];

	int x = cur / m;
	int y = cur % m;

	dp[cur][bit] = solve(cur+1, (bit >> 1));
	if ((bit & 1) == 0) {
		if (x != n-1)
			dp[cur][bit] = max(dp[cur][bit], solve(cur+1, (bit >> 1) | (1 << (m-1))) + sum(dubu[x][y], dubu[x+1][y]));

		if (y != m-1 && (bit & 2) == 0)
			dp[cur][bit] = max(dp[cur][bit], solve(cur+2, (bit >> 2)) + sum(dubu[x][y], dubu[x][y+1]));
	}

	return dp[cur][bit] %= MOD;
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> dubu[i];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';

	return 0;
}
