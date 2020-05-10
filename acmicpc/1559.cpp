#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 101
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
typedef tuple<int, int, int, int, int> tp;

string s;
int n, m, x, y, k, cnt;
bool visit[MAX][MAX][4][(1 << 9)];
int map[MAX][MAX], bo[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		memset(bo, 0, sizeof(bo));
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		for (int i=0; i<n; ++i) {
			cin >> s;
			for (int j=0; j<m; ++j) {
				if (s[j] == 'N') {
					map[i][j] = 3;
				} else if (s[j] == 'E') {
					map[i][j] = 0;
				} else if (s[j] == 'S') {
					map[i][j] = 1;
				} else {
					map[i][j] = 2;
				}
			}
		}

		cin >> k;
		int cnt = 0;
		for (int i=0; i<k; ++i) {
			cin >> x >> y;
			x--;
			y--;
			bo[x][y] = ++cnt;
		}

		queue<tp> que;
		visit[0][0][0][0] = 1;
		que.push({0, 0, 0, 0, 0});

		while (!que.empty()) {
			auto [x, y, d, bit, cnt] = que.front();
			que.pop();

			if (x == n-1 && y == m-1 && bit == (1 << k)-1) {
				cout << cnt << '\n';
				break;
			}

			int nd = (d+1) % 4;

			if (!visit[x][y][nd][bit]) {
				visit[x][y][nd][bit] = 1;
				que.push({x, y, nd, bit, cnt+1});
			}

			int nx = x + dx[(d + map[x][y]) % 4];
			int ny = y + dy[(d + map[x][y]) % 4];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (bo[nx][ny])
				bit |= (1 << (bo[nx][ny]-1));

			if (!visit[nx][ny][nd][bit]) {
				visit[nx][ny][nd][bit] = 1;
				que.push({nx, ny, nd, bit, cnt+1});
			}
		}
	}

	return 0;
}
