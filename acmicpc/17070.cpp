#include <iostream>
using namespace std;
#define MAX 17
const int dx[3] = {0, 1, 1};
const int dy[3] = {1, 0, 1};

int n, cnt;
int map[MAX][MAX];

void dfs(int x, int y, int d)
{
	if (x == n-1 && y == n-1) {
		cnt++;
		return;
	}

	for (int i=0; i<3; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (i == 0 && d == 1)
			continue;

		if (i == 1 && d == 0)
			continue;

		if (nx >= n || ny >= n || map[nx][ny] == 1)
			continue;

		if (i == 2 && (map[x][y+1] == 1 || map[x+1][y] == 1))
			continue;

		dfs(nx, ny, i);
	}
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cin >> map[i][j];

	dfs(0, 1, 0);

	cout << cnt << '\n';

	return 0;
}
