#include <iostream>
#include <cstring>
using namespace std;
#define MAX 51

const int cwy[4] = {0, 1, 0, -1};
const int cwx[4] = {1, 0, -1, 0};
const int ccwy[4] = {0, -1, 0, 1};
const int ccwx[4] = {1, 0, -1, 0};
int map[MAX][MAX], temp[MAX][MAX];
pair<int, int> upper, lower;
int r, c, t, d;
bool flag;

int main()
{
	cin >> r >> c >> t;
	for (int i=0; i<r; ++i) {
		for (int j=0; j<c; ++j) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				if (!flag) {
					upper = {i, j};
					flag = true;
				} else {
					lower = {i, j};
				}
			}
		}
	}

	while (t--) {
		memset(temp, 0, sizeof(temp));
		for (int i=0; i<r; ++i) {
			for (int j=0; j<c; ++j) {
				if (map[i][j] <= 0)
					continue;

				int cnt = 0;
				for (int k=0; k<4; ++k) {
					int ny = i + cwy[k];
					int nx = j + cwx[k];

					if (ny < 0 || nx < 0 || ny >= r || nx >= c || map[ny][nx] < 0)
						continue;

					cnt++;
				}

				if (cnt > 0) {
					int val = map[i][j] / 5;
					for (int k=0; k<4; ++k) {
						int ny = i + cwy[k];
						int nx = j + cwx[k];

						if (ny < 0 || nx < 0 || ny >= r || nx >= c || map[ny][nx] < 0)
							continue;

						temp[ny][nx] += val;
					}
					map[i][j] -= cnt * val;
				}
			}
		}

		for (int i=0; i<r; ++i) {
			for (int j=0; j<c; ++j) {
				if (map[i][j] == -1)
					continue;
				map[i][j] += temp[i][j];
				temp[i][j] = 0;
			}
		}

		for (int i=0; i<r; ++i)
			for (int j=0; j<c; ++j)
				temp[i][j] = map[i][j];

		int y = upper.first;
		int x = upper.second + 1;
		map[y][x] = 0;
		for (int i=0; i<4; ++i) {
			while (1) {
				int ny = y + ccwy[i];
				int nx = x + ccwx[i];

				if (ny == upper.first && nx == upper.second)
					break;

				if (ny < 0 || nx < 0 || ny >= r || nx >= c)
					break;

				map[ny][nx] = temp[y][x];
				y = ny;
				x = nx;
			}
		}

		y = lower.first;
		x = lower.second + 1;
		map[y][x] = 0;
		for (int i=0; i<4; ++i) {
			while (1) {
				int ny = y + cwy[i];
				int nx = x + cwx[i];

				if (ny == lower.first && nx == lower.second)
					break;

				if (ny < 0 || nx < 0 || ny >= r || nx >= c)
					break;

				map[ny][nx] = temp[y][x];
				y = ny;
				x = nx;
			}
		}
	}

	int ans = 0;
	for (int i=0; i<r; ++i)
		for (int j=0; j<c; ++j)
			if (map[i][j] > 0)
				ans += map[i][j];

	cout << ans << '\n';

	return 0;
}
