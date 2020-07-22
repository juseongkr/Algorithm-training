#include <iostream>
#include <functional>
#include <vector>
#include <tuple>
#include <queue>
#include <map>
using namespace std;
#define MAX 1001
const int INF = 1e9+7;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
typedef tuple<int, int, int> tp;

char c;
int T, k, n, m, z, sx, sy;
map<char, int> mp;
int graph[MAX][MAX];
bool visit[MAX][MAX];
int dist[MAX][MAX];
string s[MAX];

int dijkstra(int sx, int sy)
{
	priority_queue<tp, vector<tp>, greater<tp>> que;
	que.push({0, sx, sy});
	dist[sx][sy] = 0;

	while (!que.empty()) {
		auto [cost, x, y] = que.top();
		que.pop();

		if (visit[x][y])
			continue;
		visit[x][y] = 1;

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx == -1 || nx == n || ny == -1 || ny == m)
				return cost;

			int next_cost = graph[nx][ny] + cost;
			if (dist[nx][ny] > next_cost) {
				dist[nx][ny] = next_cost;
				que.push({next_cost, nx, ny});
			}
		}
	}

	return INF;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		mp.clear();
		cin >> k >> m >> n;
		for (int i=0; i<k; ++i) {
			cin >> c >> z;
			mp[c] = z;
		}

		for (int i=0; i<n; ++i) {
			cin >> s[i];
			for (int j=0; j<m; ++j) {
				if (s[i][j] == 'E') {
					sx = i;
					sy = j;
				}
			}
		}

		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				graph[i][j] = mp[s[i][j]];
				dist[i][j] = INF;
				visit[i][j] = 0;
			}
		}

		cout << dijkstra(sx, sy) << '\n';
	}

	return 0;
}
