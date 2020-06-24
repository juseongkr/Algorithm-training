#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 51
const int dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dy[8] = {1, 0, -1, 0, 1, -1, -1, 1};

int n, m;
bool map[MAX][MAX], visit[MAX][MAX];
queue<tuple<int, int, int>> que;

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				visit[i][j] = 1;
				que.push({i, j, 0});
			}
		}
	}

	int ans = 0;
	while (!que.empty()) {
		auto [x, y, cnt] = que.front();
		que.pop();
		ans = max(ans, cnt);

		for (int i=0; i<8; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || visit[nx][ny])
				continue;

			visit[nx][ny] = 1;
			que.push({nx, ny, cnt+1});
		}
	}
	
	cout << ans << '\n';

	return 0;
}
