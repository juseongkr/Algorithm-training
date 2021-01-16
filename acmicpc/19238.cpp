#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
using namespace std;
#define MAX 21
typedef pair<int, int> pi;
typedef tuple<int ,int, int> tp;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

map<pi, pi> route;
bool graph[MAX][MAX], visit[MAX][MAX];
int n, m, f, tx, ty, ax, ay, bx, by;

tp pick(int sx, int sy)
{
	vector<tp> vec;
	queue<tp> que;
	memset(visit, 0, sizeof(visit));

	que.push({sx, sy, 0});
	visit[sx][sy] = 1;

	while (!que.empty()) {
		auto [x, y, z] = que.front();
		que.pop();

		if (route.count({x, y})) {
			vec.push_back({z, x, y});
		}

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n || visit[nx][ny] || graph[nx][ny])
				continue;

			visit[nx][ny] = 1;
			que.push({nx, ny, z+1});
		}
	}

	if (vec.size() == 0)
		return {-1, -1, -1};

	sort(vec.begin(), vec.end());

	return vec[0];
}

tp drop(int sx, int sy)
{
	queue<tp> que;
	memset(visit, 0, sizeof(visit));

	que.push({sx, sy, 0});
	visit[sx][sy] = 1;

	while (!que.empty()) {
		auto [x, y, z] = que.front();
		que.pop();

		if (route[{sx, sy}] == make_pair(x, y)) {
			route.erase({sx, sy});
			return {z, x, y};
		}

		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n || visit[nx][ny] || graph[nx][ny])
				continue;

			visit[nx][ny] = 1;
			que.push({nx, ny, z+1});
		}
	}

	return {-1, -1, -1};
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> f;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cin >> graph[i][j];

	cin >> tx >> ty;
	tx--;
	ty--;
	for (int i=0; i<m; ++i) {
		cin >> ax >> ay >> bx >> by;
		ax--;
		ay--;
		bx--;
		by--;
		route[{ax, ay}] = {bx, by};
	}

	for (int i=0; i<m; ++i) {
		auto [z, x, y] = pick(tx, ty);
		if (z == -1 || f == 0 || z > f) {
			cout << "-1\n";
			return 0;
		}
		f -= z;

		auto [nz, nx, ny] = drop(x, y);
		if (nz == -1 || f == 0 || nz > f) {
			cout << "-1\n";
			return 0;
		}
		f += nz;

		tx = nx;
		ty = ny;
	}

	cout << f << '\n';

	return 0;
}
