#include <iostream>
using namespace std;
#define MAX 51

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int n, m, r, c, d;
int map[MAX][MAX];

int main()
{
	cin >> n >> m >> r >> c >> d;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	while (1) {
		if (map[r][c] == 0)
			map[r][c] = 2;

		if (map[r-1][c] && map[r+1][c] && map[r][c-1] && map[r][c+1]) {
			if (map[r-dy[d]][c-dx[d]] == 1) {
				break;
			} else {
				r -= dy[d];
				c -= dx[d];
			}
		} else {
			d = (d + 3) % 4;
			if (map[r+dy[d]][c+dx[d]] == 0) {
				r += dy[d];
				c += dx[d];
			}
		}
	}

	int ans = 0;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (map[i][j] == 2)
				ans++;

	cout << ans << '\n';

	return 0;
}
