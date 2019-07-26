#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 8

const int dy[9] = {0, 0, 1, -1, 1, -1, 1, -1, 0};
const int dx[9] = {1, -1, 0, 0, 1, 1, -1, -1, 0};
int visit[MAX][MAX][9];
string map[MAX];

int main()
{
	for (int i=0; i<8; ++i)
		cin >> map[i];

	queue<tuple<int, int, int>> que;
	visit[7][0][0] = 1;
	que.push({7, 0, 0});

	while (!que.empty()) {
		auto [y, x, t] = que.front();
		que.pop();

		if (y == 0 && x == 7) {
			cout << "1\n";
			return 0;
		}

		for (int i=0; i<9; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			int nt = min(t+1, 8);

			if (ny < 0 || nx < 0 || ny >= 8 || nx >= 8)
				continue;

			if (ny-t >= 0 && map[ny-t][nx] == '#')
				continue;

			if (ny-t-1 >= 0 && map[ny-t-1][nx] == '#')
				continue;

			if (!visit[ny][nx][nt]) {
				visit[ny][nx][nt] = 1;
				que.push({ny, nx, nt});
			}
		}
	}
	cout << "0\n";

	return 0;
}
