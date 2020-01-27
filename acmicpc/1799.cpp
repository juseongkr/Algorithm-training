#include <iostream>
using namespace std;
#define MAX 11
const int dx[2] = {-1, -1};
const int dy[2] = {1, -1};

int n;
int map[MAX][MAX], color[MAX][MAX], visit[MAX][MAX], ans[2];

bool check(int x, int y)
{
	for (int i=0; i<2; ++i) {
		int nx = x;
		int ny = y;
		
		while (1) {
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				break;

			if (visit[nx][ny])
				return false;

			nx += dx[i];
			ny += dy[i];
		}
	}
	return true;
}

void solve(int cur, int cnt, int col)
{
	ans[col] = max(ans[col], cnt);
	for (int i=cur+1; i<n*n; ++i) {
		int x = i/n;
		int y = i%n;

		if (color[x][y] != col || !map[x][y] || !check(x, y))
			continue;

		visit[x][y] = 1;
		solve(i, cnt+1, col);
		visit[x][y] = 0;
	}
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> map[i][j];
			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 && j % 2))
				color[i][j] = 1;
		}
	}

	solve(-1, 0, 1);
	solve(-1, 0, 0);

	cout << ans[0] + ans[1] << '\n';

	return 0;
}
