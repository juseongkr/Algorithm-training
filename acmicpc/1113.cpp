#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 52
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

string s[MAX];
int H, n, m, ans;
int map[MAX][MAX];
bool filled[MAX][MAX];

void bfs()
{
	queue<pair<int, int>> que;
	filled[0][0] = 1;
	que.push({0, 0});

	while (!que.empty()) {
		auto [x, y] = que.front();
		que.pop();

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n+2 || ny < 0 || ny >= m+2 || filled[nx][ny])
				continue;

			filled[nx][ny] = 1;
			que.push({nx, ny});
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> s[i];
	
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			map[i][j] = s[i-1][j-1]-'0';
			H = max(H, map[i][j]);
		}
	}

	for (int h=1; h<=H; ++h) {
		memset(filled, 0, sizeof(filled));
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=m; ++j)
				filled[i][j] = map[i][j] < h ? 0 : 1;

		bfs();

		for (int i=0; i<n+2; ++i)
			for (int j=0; j<m+2; ++j)
				if (!filled[i][j])
					ans++;
	}
	cout << ans << '\n';

	return 0;
}
