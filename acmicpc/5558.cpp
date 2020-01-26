#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 1001
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m, k, sx, sy;
bool visit[MAX][MAX][9];
string map[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i=0; i<n; ++i) {
		cin >> map[i];
		for (int j=0; j<m; ++j) {
			if (map[i][j] == 'S') {
				sx = i;
				sy = j;
			}
		}
	}

	queue<tuple<int, int, int>> que;
	que.push({sx, sy, 0});
	visit[sx][sy][0] = 1;

	int cnt = 0;
	while (!que.empty()) {
		cnt++;
		int sz = que.size();
		for (int t=0; t<sz; ++t) {
			auto [x, y, z] = que.front();
			que.pop();

			for (int i=0; i<4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z;

				if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == 'X')
					continue;

				if (map[nx][ny]-'0' == z+1)
					nz++;

				if (nz == k) {
					cout << cnt << '\n';
					return 0;
				}

				if (!visit[nx][ny][nz]) {
					visit[nx][ny][nz] = 1;
					que.push({nx, ny, nz});
				}
			}
		}
	}

	return 0;
}
