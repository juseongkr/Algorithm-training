#include <iostream>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

int h, w, t;
char graph[102][102];
int step[3][102][102];
int a[4] = {0, 1, 0, -1};
int b[4] = {1, 0, -1, 0};
queue<tuple<int, int, int>> start[3];

void bfs(int n)
{
	auto [tx, ty, _] = start[n].front();
	step[n][tx][ty] = 0;

	while (!start[n].empty()) {
		auto [x, y, cnt] = start[n].front();
		start[n].pop();

		for (int i=0; i<4; ++i) {
			int next_x = x + a[i];
			int next_y = y + b[i];
			
			if (next_x < 0 || next_y < 0 || next_x > h + 1 || next_y > w + 1 ||
			    graph[next_x][next_y] == '*')
				continue;

			if (graph[next_x][next_y] == '#' && step[n][next_x][next_y] > cnt+1) {

				start[n].push({next_x, next_y, cnt+1});
				step[n][next_x][next_y] = cnt+1;

			} else if (graph[next_x][next_y] == '.' && step[n][next_x][next_y] > cnt) {

				start[n].push({next_x, next_y, cnt});
				step[n][next_x][next_y] = cnt;

			}
		}
	}
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &h, &w);
		for (int i=1; i<h+1; ++i)
			scanf("%s", (graph[i]+1));

		for (int i=0; i<h+2; ++i) {
			for (int j=0; j<w+2; ++j) {
				if (i == 0 || j == 0 || i == h + 1 || j == w + 1) {
					graph[i][j] = '.';
				} else if (graph[i][j] == '$') {
					if (start[0].empty())
						start[0].push({i, j, 0});
					else
						start[1].push({i, j, 0});
					graph[i][j] = '.';
				}
				step[0][i][j] = step[1][i][j] = step[2][i][j] = INT_MAX;
			}
		}

		start[2].push({0, 0, 0});
		for (int i=0; i<3; ++i)
			bfs(i);

		int result = INT_MAX;
		for (int i=0; i<h+2; ++i) {
			for (int j=0; j<w+2; ++j) {
				int temp = step[0][i][j] + step[1][i][j] + step[2][i][j];
				if (graph[i][j] == '#')
					temp -= 2;
				result = min(result, temp);
			}
		}
		printf("%d\n", result);
	}

	return 0;
}
