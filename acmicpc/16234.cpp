#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define MAX 51

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
int map[MAX][MAX];
bool visit[MAX][MAX];
int n, l, r;

bool bfs()
{
	bool move = false;
	memset(visit, false, sizeof(visit));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (visit[i][j])
				continue;
			queue<pair<int, int>> que, log;
			int total = map[i][j];
			visit[i][j] = true;
			que.push({i, j});
			log.push({i, j});

			while (!que.empty()) {
				int y = que.front().first;
				int x = que.front().second;
				que.pop();

				for (int k=0; k<4; ++k) {
					int ny = y + dy[k];
					int nx = x + dx[k];

					if (ny < 0 || nx < 0 || nx >= n || ny >= n || visit[ny][nx])
						continue;

					int diff = abs(map[ny][nx] - map[y][x]);
					if (l <= diff && diff <= r) {
						total += map[ny][nx];
						visit[ny][nx] = true;
						que.push({ny, nx});
						log.push({ny, nx});
						move = true;
					}
				}
			}

			int val = total / log.size();
			while (!log.empty()) {
				int y = log.front().first;
				int x = log.front().second;
				log.pop();
				map[y][x] = val;
			}
		}
	}
	return move;
}


int main()
{
	cin >> n >> l >> r;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cin >> map[i][j];

	int ans = 0;
	while (1) {
		if (bfs())
			ans++;
		else
			break;
	}
	cout << ans << '\n';

	return 0;
}
