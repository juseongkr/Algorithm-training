#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
#define MAX 201

const int dy[6] = {-2, -2, 0, 0, 2, 2};
const int dx[6] = {-1, 1, -2, 2, -1, 1};
int n, sy, sx, ey, ex;
int map[MAX][MAX], visit[MAX][MAX];

int main()
{
	cin >> n;
	cin >> sy >> sx >> ey >> ex;

	queue<tuple<int, int, int>> que;
	visit[sy][sx] = 1;
	que.push({sy, sx, 0});

	while (!que.empty()) {
		auto [y, x, c] = que.front();
		que.pop();

		if (y == ey && x == ex) {
			cout << c << '\n';
			return 0;
		}

		for (int i=0; i<6; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;

			if (visit[ny][nx])
				continue;

			visit[ny][nx] = 1;
			que.push({ny, nx, c+1});
		}
	}
	cout << "-1\n";

	return 0;
}
