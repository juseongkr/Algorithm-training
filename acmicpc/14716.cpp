#include <iostream>
using namespace std;
#define MAX 251
const int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int n, m, cnt;
bool map[MAX][MAX], visit[MAX][MAX];

void dfs(int x, int y)
{
	if (visit[x][y])
		return;

	visit[x][y] = 1;
	for (int i=0; i<8; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m || !map[nx][ny])
			continue;

		dfs(nx, ny);
	}
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (map[i][j] && !visit[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << '\n';

	return 0;
}
