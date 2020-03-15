#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define MAX 11
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
typedef tuple<int, int, int> ti;

int n, m, label;
int map[MAX][MAX];
bool visit[MAX][MAX];
vector<ti> island;

class UnionFind {
public:
	vector<int> p;
	UnionFind(int n) { p.resize(n+1, -1); }
	int find(int x)
	{
		if (p[x] < 0)
			return x;
		return p[x] = find(p[x]);
	}

	bool uni(int x, int y)
	{
		x = find(x);
		y = find(y);
		if (x == y)
			return false;
		if (p[x] < p[y])
			swap(x, y);
		p[y] += p[x];
		p[x] = y;
		return true;
	}
};

void dfs(int x, int y)
{
	map[x][y] = label;
	visit[x][y] = 1;
	for (int i=0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m || visit[nx][ny] || !map[nx][ny])
			continue;

		dfs(nx, ny);
	}
}

void bridge(int x, int y)
{
	for (int i=0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		int dist = 0;
		while (1) {
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny])
				break;
			nx += dx[i];
			ny += dy[i];
			dist++;
		}

		if (nx < 0 || nx >= n || ny < 0 || ny >= m || !map[nx][ny])
			continue;

		if (map[nx][ny] != map[x][y] && dist >= 2) {
			island.push_back({dist, map[x][y], map[nx][ny]});
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (!visit[i][j] && map[i][j]) {
				label++;
				dfs(i, j);
			}
		}
	}

	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (map[i][j])
				bridge(i, j);

	sort(island.begin(), island.end());

	UnionFind u(label);
	int ans = 0, cnt = 0;
	for (int i=0; i<island.size(); ++i) {
		auto [z, x, y] = island[i];
		if (u.uni(x, y)) {
			ans += z;
			if (++cnt == label-1) {
				cout << ans << '\n';
				return 0;
			}
		}
	}
	cout << "-1\n";

	return 0;
}
