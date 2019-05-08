#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

#define MAX 501

int n, m, a, b;
string map[MAX];
int visit[MAX][MAX][64];
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int bfs(int i, int j)
{
	queue<tuple<int, int, int, int>> que;
	que.push({i, j, 0, 0});

	while (!que.empty()) {
		auto [y, x, step, key] = que.front();
		que.pop();

		if (map[y][x] == '1')
			return step;

		for (int i=0; i<4; ++i) {
			int next_y = y + dy[i];
			int next_x = x + dx[i];
			char next = map[next_y][next_x];

			if (next_y < 0 || next_x < 0 || next_y >= n || next_x >= m)
				continue;

			if (next == '#' || visit[next_y][next_x][key] == 1)
				continue;

			if (next == '.' || next == '1') {
				visit[next_y][next_x][key] = 1;
				que.push({next_y, next_x, step+1, key});

			} else if ('a' <= next && next <= 'f') {
				int next_key = key | (1 << (next-'a'));
				if (visit[next_y][next_x][next_key] == 0) {
					visit[next_y][next_x][key] = 1;
					visit[next_y][next_x][next_key] = 1;
					que.push({next_y, next_x, step+1, next_key});
				}

			} else if ('A' <= next && next <= 'F') {
				if (key & (1 << (next-'A'))) {
					visit[next_y][next_x][key] = 1;
					que.push({next_y, next_x, step+1, key});
				}
			}
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> map[i];
		for (int j=0; j<m; ++j) {
			if (map[i][j] == '0') {
				map[i][j] = '.';
				a = i;
				b = j;
			}
		}
	}

	cout << bfs(a, b) << '\n';

	return 0;
}
