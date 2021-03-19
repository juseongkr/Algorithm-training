#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int m, n, p, y, hp, ans;
int dps[26], act[26];
bool visit[MAX][MAX];
queue<pair<int, int>> que;
string map[MAX];
char x;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> m >> n >> p;
	for (int i=0; i<m; ++i) {
		cin >> map[i];
		for (int j=0; j<n; ++j) {
			if (map[i][j] == 'B') {
				que.push({i, j});
				visit[i][j] = 1;
			}
		}
	}

	for (int i=0; i<p; ++i) {
		cin >> x >> y;
		dps[x-'a'] = y;
	}
	cin >> hp;

	while (hp > 0) {
		int len = que.size();
		while (len--) {
			auto [x, y] = que.front();
			que.pop();

			if ('a' <= map[x][y] && map[x][y] <= 'z') {
				act[map[x][y]-'a'] = 1;
				ans++;
			}

			for (int i=0; i<4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= m || ny < 0 || ny >= n || map[nx][ny] == 'X' || visit[nx][ny])
					continue;

				visit[nx][ny] = 1;
				que.push({nx, ny});
			}
		}

		for (int i=0; i<p; ++i)
			if (act[i])
				hp -= dps[i];
	}

	cout << ans << '\n';

	return 0;
}
