#include <iostream>
#include <queue>
using namespace std;

queue<pair<pair<int, int>, int>> que;
pair<pair<int, int>, int> t, start, dest;
char building[30][30][30];
int visit[30][30][30], step[30][30][30];
int A[6] = {1, 0, 0, -1, 0, 0};
int B[6] = {0, 1, 0, 0, -1, 0};
int C[6] = {0, 0, 1, 0, 0, -1};
int l, r, c, ans;

void bfs(int z, int y, int x)
{
	visit[z][y][x] = 1;
	que.push({{z, y}, x});

	while (!que.empty()) {
		t = que.front();
		que.pop();

		for (int i=0; i<6; ++i) {
			int next_z = t.first.first + A[i];
			int next_y = t.first.second + B[i];
			int next_x = t.second + C[i];

			if (next_x < 0 || next_y < 0 || next_z < 0 ||
			    next_z >= l || next_y >= r || next_x >= c)
				continue;

			if (visit[next_z][next_y][next_x] == 0 &&
			    building[next_z][next_y][next_x] == '.') {

				que.push({{next_z, next_y}, next_x});
				visit[next_z][next_y][next_x] = 1;
				step[next_z][next_y][next_x] = step[t.first.first][t.first.second][t.second] + 1;
			}
		}
	}
}

int main()
{
	string str;

	while (scanf("%d %d %d", &l, &r, &c) &&
	       l != 0 && r != 0 && c != 0) {

		for (int i=0; i<l; ++i) {
			for (int j=0; j<r; ++j) {
				cin >> str;
				for (int k=0; k<c; ++k) {
					if (str[k] == 'E') {
						dest = {{i, j}, k};
						building[i][j][k] = '.';
					} else if (str[k] == 'S') {
						start = {{i, j,}, k};
						building[i][j][k] = '.';
					} else {
						building[i][j][k] = str[k];
					}
				}
			}
		}
		
		for (int i=0; i<l; ++i) {
			for (int j=0; j<r; ++j) {
				for (int k=0; k<c; ++k) {
					visit[i][j][k] = 0;
					step[i][j][k] = 0;
				}
			}
		}

		bfs(start.first.first, start.first.second, start.second);

		ans = step[dest.first.first][dest.first.second][dest.second];

		if (ans)
			printf("Escaped in %d minute(s).\n", ans);
		else
			printf("Trapped!\n");
	}

	return 0;
}
