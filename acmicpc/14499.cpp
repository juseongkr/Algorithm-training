#include <iostream>
using namespace std;
#define MAX 21

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {1, -1, 0, 0};
int map[MAX][MAX];
int dice[7];

int main()
{
	int n, m, y, x, t, k;

	cin >> n >> m >> y >> x >> t;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	while (t--) {
		cin >> k;
		int ny = y + dy[k-1];
		int nx = x + dx[k-1];
		int temp;

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
			continue;

		switch (k) {
		case 1:
			temp = dice[1];
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = temp;
			break;

		case 2:
			temp = dice[1];
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = temp;
			break;

		case 3:
			temp = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = temp;
			break;

		case 4:
			temp = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = temp;
			break;
		}

		if (map[ny][nx] == 0) {
			map[ny][nx] = dice[6];
		} else {
			dice[6] = map[ny][nx];
			map[ny][nx] = 0;
		}
		cout << dice[1] << '\n';
		y = ny;
		x = nx;
	}

	return 0;
}
