#include <iostream>
#include <cstring>
using namespace std;
#define MAX 101

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int apple[MAX][MAX], map[MAX][MAX];
int now, d, len = 1;

int main()
{
	int n, m, a, b;

	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		apple[a-1][b-1] = 1;
	}

	memset(map, -1, sizeof(map));
	map[0][0] = 0;

	cin >> m;
	int x = 0, y = 0;
	for (int i=0; i<=m; ++i) {
		int t = n*n+1;
		char c = 'L';
		if (i < m)
			cin >> t >> c;

		while (now < t) {
			now++;
			x += dx[d];
			y += dy[d];

			if (x < 0 || y < 0 || x >= n || y >= n) {
				cout << now << '\n';
				return 0;
			}
			if (apple[x][y]) {
				apple[x][y] = 0;
				len++;
			}

			if (map[x][y] != -1 && now - map[x][y] <= len) {
				cout << now << '\n';
				return 0;
			}
			map[x][y] = now;
		}

		if (c == 'L')
			d = (d + 3) % 4;
		else
			d = (d + 1) % 4;
	}

	return 0;
}
