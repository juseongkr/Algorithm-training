#include <iostream>
#include <cstring>
using namespace std;
#define MAX 106

string s;
int n, m, k, ans, len;
char map[MAX][MAX];
int dp[MAX][MAX][MAX];

int solve(int x, int y, int cnt)
{
	if (dp[x][y][cnt] != -1)
		return dp[x][y][cnt];

	if (cnt == len)
		return 1;

	dp[x][y][cnt] = 0;
	for (int i=1; i<=k; ++i) {
		if (y+i < m && map[x][y+i] == s[cnt])
			dp[x][y][cnt] += solve(x, y+i, cnt+1);
		if (x+i < n && map[x+i][y] == s[cnt])
			dp[x][y][cnt] += solve(x+i, y, cnt+1);
		if (y-i >= 0 && map[x][y-i] == s[cnt])
			dp[x][y][cnt] += solve(x, y-i, cnt+1);
		if (x-i >= 0 && map[x-i][y] == s[cnt])
			dp[x][y][cnt] += solve(x-i, y, cnt+1);
	}
	return dp[x][y][cnt];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];
	cin >> s;
	len = s.length();
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (map[i][j] == s[0])
				ans += solve(i, j, 1);
	cout << ans << '\n';

	return 0;
}
