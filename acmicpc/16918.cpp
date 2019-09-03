#include <iostream>
#include <vector>
using namespace std;
#define MAX 201
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m, t;
char map[MAX][MAX];
int tick[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> t;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'O')
				tick[i][j] = 3;
		}
	}

	for (int k=1; k<=t; ++k) {
		for (int x=0; x<n; ++x) {
			for (int y=0; y<m; ++y) {
				if (tick[x][y] != k)
					continue;

				map[x][y] = '.';
				for (int i=0; i<4; ++i) {
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (nx < 0 || ny < 0 || nx >= n || ny >= m)
						continue;

					map[nx][ny] = '.';
				}
			}
		}
		if (k % 2 != 0)
			continue;

		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				if (map[i][j] == '.') {
					map[i][j] = 'O';
					tick[i][j] = k+3;
				}
			}
		}
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j)
			cout << map[i][j];
		cout << '\n';
	}

	return 0;
}
