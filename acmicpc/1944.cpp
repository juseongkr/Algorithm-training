#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define MAX 51
const int INF = 1e9+7;

class Edge {
public:
	int u, v, c;
	Edge(int x, int y, int z) : u(x), v(y), c(z) { }
	bool operator<(const Edge &x) const { return c < x.c; }
};

vector<Edge> v;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
vector<pair<int, int>> key;
char map[MAX][MAX];
int visit[MAX*5][MAX*5];
int dist[MAX*5][MAX*5];
int num[MAX][MAX];
int root[MAX*5];
int n, m;

int find(int n)
{
	if (root[n] < 0)
		return n;
	return root[n] = find(root[n]);
}

bool uni(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return false;
	root[y] = x;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	m++;
	int idx = 0;
	memset(num, -1, sizeof(num));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'S')
				map[i][j] = 'K';
			if (map[i][j] == 'K') {
				key.push_back({i, j});
				num[i][j] = idx++;
			}
		}
	}

	memset(dist, 0, sizeof(dist));
	for (int i=0; i<m; ++i)
		for (int j=0; j<m; ++j)
			if (i != j)
				dist[i][j] = INF;

	for (int i=0; i<key.size(); ++i) {
		memset(visit, 0, sizeof(visit));
		queue<pair<int, int>> que;

		int node = 0;
		visit[key[i].first][key[i].second] = 1;
		que.push(key[i]);
		while (!que.empty()) {
			int sz = que.size();
			for (int j=0; j<sz; ++j) {
				int x = que.front().first;
				int y = que.front().second;
				que.pop();

				if (map[x][y] == 'K')
					dist[i][num[x][y]] = min(dist[i][num[x][y]], node);

				for (int k=0; k<4; ++k) {
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx < 0 || ny < 0 || nx >= n || ny >= n || visit[nx][ny] || map[nx][ny] == '1')
						continue;

					visit[nx][ny] = 1;
					que.push({nx, ny});
				}
			}
			node++;
		}
	}

	for (int i=0; i<m; ++i) {
		for (int j=0; j<m; ++j) {
			if (dist[i][j] == INF) {
				cout << "-1\n";
				return 0;
			}
		}
	}

	for (int i=0; i<m; ++i)
		for (int j=0; j<m; ++j)
			v.push_back({i, j, dist[i][j]});

	fill(root, root+MAX*5, -1);
	sort(v.begin(), v.end());

	int cnt = 0, ans = 0;
	for (int i=0; i<v.size(); ++i) {
		if (uni(v[i].u, v[i].v)) {
			ans += v[i].c;
			if (++cnt == m)
				break;
		}
	}
	cout << ans << '\n';

	return 0;
}
