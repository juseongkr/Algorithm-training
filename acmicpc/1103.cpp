#include <iostream>
#include <cstring>
using namespace std;
#define MAX 51
const int INF = 1e9+7;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

char c;
int n, m;
int map[MAX][MAX], dp[MAX][MAX];
bool visit[MAX][MAX];

int solve(int x, int y)
{
	if (visit[x][y])
		return INF;

	if (~dp[x][y])
		return dp[x][y];

	dp[x][y] = visit[x][y] = 1;
	for (int i=0; i<4; ++i) {
		int nx = x + dx[i] * map[x][y];
		int ny = y + dy[i] * map[x][y];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m || !map[nx][ny])
			continue;

		dp[x][y] = max(dp[x][y], solve(nx, ny) + 1);
	}
	visit[x][y] = 0;

	return dp[x][y];
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> c;
			if ('0' <= c && c <= '9')
				map[i][j] = c-'0';
		}
	}

	memset(dp, -1, sizeof(dp));
	int ans = solve(0, 0);
	if (ans >= INF)
		cout << "-1\n";
	else
		cout << ans << '\n';

	return 0;
}
