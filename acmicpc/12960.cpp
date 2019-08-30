#include <iostream>
#include <cstring>
using namespace std;
#define MAX 48

int n, m;
char s[MAX][MAX];
string map[MAX];
int dp[MAX*4][1<<4];

int solve(int cur, int bit)
{
	if (cur == n*m)
		return 0;

	if (dp[cur][bit] != -1)
		return dp[cur][bit];

	int x = cur / m;
	int y = cur % m;
	
	if (map[x][y] == 'X') {
		dp[cur][bit] = solve(cur+1, (bit >> 1));

	} else {
		dp[cur][bit] = solve(cur+1, (bit >> 1));
		if ((bit & 1) == 0) {

			if ((x + y) % 2 == 0) {
				if (x+1 < n && y+1 < m)
					if (map[x][y+1] == '.' && map[x+1][y] == '.' && (bit & 2) == 0)
						dp[cur][bit] = max(dp[cur][bit], solve(cur+2, (bit >> 2) | (1 << (m-2))) + 1);

			} else {
				if (x+1 < n && y+1 < m)
					if (map[x][y+1] == '.' && map[x+1][y+1] == '.' && (bit & 2) == 0)
						dp[cur][bit] = max(dp[cur][bit], solve(cur+2, (bit >> 2) | (1 << (m-1))) + 1);

				if (x+1 < n && y-1 >= 0)
					if (map[x+1][y] == '.' && map[x+1][y-1] == '.' && (bit & (1 << (m-1))) == 0)
						dp[cur][bit] = max(dp[cur][bit], solve(cur+1, (bit >> 1) | (1 << (m-1)) | (1 << (m-2))) + 1);

				if (x+1 < n && y+1 < m)
					if (map[x+1][y] == '.' && map[x+1][y+1] == '.')
						dp[cur][bit] = max(dp[cur][bit], solve(cur+2, (bit >> 2) | (1 << (m-1)) | (1 << (m-2))) + 1);
			}

		}
	}

	return dp[cur][bit];
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> s[i];

	for (int j=0; j<m; ++j)
		for (int i=0; i<n; ++i)
			map[j] += s[i][j];

	swap(n, m);
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';

	return 0;
}
