#include <iostream>
using namespace std;
#define MAX 6

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
char map[MAX][MAX];
bool visit[MAX][MAX];
int r, c, k, ans;

void dfs(int x, int y, int cnt)
{
	if (cnt > k)
		return;

	if (x == 0 && y == c-1 && cnt == k) {
		ans++;
		return;
	}

	visit[x][y] = true;
	for (int i=0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= r || ny >= c || visit[nx][ny] || map[nx][ny] == 'T')
			continue;
	
		dfs(nx, ny, cnt+1);
	}
	visit[x][y] = false;
}

int main()
{
	cin >> r >> c >> k;
	for (int i=0; i<r; ++i)
		for (int j=0; j<c; ++j)
			cin >> map[i][j];

	dfs(r-1, 0, 1);

	cout << ans << '\n';

	return 0;
}
