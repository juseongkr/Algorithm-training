#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 202
typedef pair<int, int> pi;
typedef tuple<int, int, int> tp;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, k, s, x, y;
vector<pi> vec[1001];
bool visit[MAX][MAX];
int map[MAX][MAX];

void bfs()
{
	queue<tp> que;

	for (int i=1; i<=k; ++i) {
		if (vec[i].size()) {
			for (int j=0; j<vec[i].size(); ++j) {
				auto [x, y] = vec[i][j];
				que.push({i, x, y});
				visit[x][y] = 1;
			}
		}
	}

	while (!que.empty() && s--) {
		int cnt = que.size();
		while (cnt--) {
			auto [num, x, y] = que.front();
			que.pop();

			for (int i=0; i<4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 1 || nx >= n+1 || ny < 1 || ny >= n+1 || visit[nx][ny])
					continue;

				map[nx][ny] = num;
				visit[nx][ny] = 1;
				que.push({num, nx, ny});
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			cin >> map[i][j];
			if (map[i][j])
				vec[map[i][j]].push_back({i, j});
		}
	}
	cin >> s >> x >> y;

	bfs();

	cout << map[x][y] << '\n';

	return 0;
}
