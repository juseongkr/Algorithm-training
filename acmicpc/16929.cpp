#include <iostream>
#include <cstring>
using namespace std;
#define MAX 51

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
pair<int, int> start;
int visit[MAX][MAX];
char map[MAX][MAX];
bool flag;
int n, m;

void dfs(int y, int x, int cnt, char color)
{
	for (int i=0; i<4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
			continue;

		if (!visit[ny][nx] && map[ny][nx] == color) {
			visit[ny][nx] = 1;
			dfs(ny, nx, cnt+1, color);
		}
		
		if (cnt >= 4 && start.first == ny && start.second == nx) {
			flag = true;
			return;
		}
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
			if (visit[i][j])
				continue;
			memset(visit, 0, sizeof(visit));
			start = {i, j};
			visit[i][j] = 1;
			dfs(i, j, 1, map[i][j]);
			if (flag) {
				cout << "Yes\n";
				return 0;
			}
		}
	}
	cout << "No\n";

	return 0;
}
