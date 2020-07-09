#include <iostream>
using namespace std;
#define MAX 102
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, x, y, ans;
int map[MAX][MAX], visit[MAX][MAX];

void dfs(int x, int y)
{
	if (map[x][y]) {
		ans++;
		return;
	}

	visit[x][y] = 1;
	for (int i=0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX || visit[nx][ny])
			continue;

		dfs(nx, ny);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		map[x][y] = 1;
	}

	dfs(0, 0);

	cout << ans << '\n';

	return 0;
}
