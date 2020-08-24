#include <iostream>
#include <cstring>
using namespace std;
#define MAX 501
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m;
string s;
int map[MAX][MAX], dp[MAX][MAX];

int solve(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m)
		return 1;

	if (~dp[x][y])
		return dp[x][y];
	
	dp[x][y] = 0;
	int nx = x + dx[map[x][y]];
	int ny = y + dy[map[x][y]];

	return dp[x][y] = solve(nx, ny);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> s;
		for (int j=0; j<m; ++j) {
			if (s[j] == 'L')
				map[i][j] = 2;
			else if (s[j] == 'R')
				map[i][j] = 0;
			else if (s[j] == 'U')
				map[i][j] = 3;
			else
				map[i][j] = 1;
		}
	}

	int ans = 0;
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			ans += solve(i, j);

	cout << ans << '\n';

	return 0;
}
