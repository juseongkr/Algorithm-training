#include <iostream>
using namespace std;
#define MAX 251
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m, s, w, wolf, sheep;
int visit[MAX][MAX];
char map[MAX][MAX];

void dfs(int x, int y)
{
	visit[x][y] = 1;
	if (map[x][y] == 'v')
		w++;
	else if (map[x][y] == 'k')
		s++;

	for (int i=0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;
		
		if (!visit[nx][ny] && map[nx][ny] != '#') {
			visit[nx][ny] = 1;
			dfs(nx, ny);
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
			if (map[i][j] != '#' && !visit[i][j]) {
				s = 0, w = 0;
				dfs(i, j);
				if (s != 0 || w != 0) {
					if (s <= w)
						wolf += w;
					else
						sheep += s;
				}
			}
		}
	}
	cout << sheep << " " << wolf << '\n';

	return 0;
}
