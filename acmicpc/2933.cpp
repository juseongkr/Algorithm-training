#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 101

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
vector<pair<int, int>> group;
bool visit[MAX][MAX];
char map[MAX][MAX];
int r, c, n, s;

void dfs(int y, int x)
{
	if (map[y][x] == '.' || visit[y][x])
		return;

	visit[y][x] = true;
	group.push_back({y, x});

	for (int i=0; i<4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c)
			continue;

		dfs(ny, nx);
	}
}

void fall()
{
	memset(visit, false, sizeof(visit));
	for (int y=0; y<r; ++y) {
		for (int x=0; x<c; ++x) {
			if (map[y][x] == '.' || visit[y][x])
				continue;

			group.clear();
			dfs(y, x);

			vector<int> low(c, -1);
			for (auto &p : group) {
				low[p.second] = max(low[p.second], p.first);
				map[p.first][p.second] = '.';
			}

			int minimum = r;
			for (int i, j=0; j<c; ++j) {
				if (low[j] == -1)
					continue;

				i = low[j];
				while (i < r && map[i][j] == '.')
					i++;
				minimum = min(minimum, i - low[j] - 1);
			}

			for (auto &p : group) {
				p.first += minimum;
				visit[p.first][p.second] = true;
				map[p.first][p.second] = 'x';
			}
		}
	}
}

int main()
{
	cin >> r >> c;
	for (int i=0; i<r; ++i)
		for (int j=0; j<c; ++j)
			cin >> map[i][j];

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> s;
		if (i % 2 == 0) {
			for (int j=0; j<c; ++j) {
				if (map[r-s][j] == 'x') {
					map[r-s][j] = '.';
					break;
				}
			}
		} else {
			for (int j=c-1; j>=0; j--) {
				if (map[r-s][j] == 'x') {
					map[r-s][j] = '.';
					break;
				}
			}
		}
		fall();
	}

	for (int i=0; i<r; ++i) {
		for (int j=0; j<c; ++j)
			cout << map[i][j];
		cout << '\n';
	}

	return 0;
}
