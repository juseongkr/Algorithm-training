#include <iostream>
using namespace std;
#define MAX 101
const int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[8] = {1, 0, -1, 0, -1, 1, 1, -1};

int n, m;
string map[MAX];

void dfs(int x, int y)
{
	map[x][y] = '*';
	for (int i=0; i<8; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == '*')
			continue;

		dfs(nx, ny);
	}
}

int main()
{
	while (cin >> n >> m) {
		if (n == 0 && m == 0)
			break;

		for (int i=0; i<n; ++i)
			cin >> map[i];

		int ans = 0;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				if (map[i][j] == '@') {
					dfs(i, j);
					ans++;
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
