#include <iostream>
using namespace std;
#define MAX 1001
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m, x, y, z;
bool visit[MAX][MAX];
string map[MAX];

void dfs(int x, int y, int z, char t)
{
	if (visit[x][y])
		return;
	visit[x][y] = 1;

	map[x][y] = z+'0';
	for (int i=0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m || visit[nx][ny])
			continue;

		if (map[nx][ny] == t)
			dfs(nx, ny, z, t);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> map[i];
	cin >> x >> y >> z;

	dfs(x, y, z, map[x][y]);

	for (int i=0; i<n; ++i)
		cout << map[i] << '\n';

	return 0;
}
