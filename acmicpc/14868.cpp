#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define MAX 2001
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

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
		if (x != y) {
			p[x] += p[y];
			p[y] = x;
			return true;
		}
		return false;
	}
};

int map[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, k, x, y;
	queue<int> que;

	cin >> n >> k;
	UnionFind u = UnionFind(n*MAX+n);
	memset(map, -1, sizeof(map));
	for (int i=0; i<k; ++i) {
		cin >> x >> y;
		x--;
		y--;
		que.push(x*MAX+y);
		map[x][y] = i;

		for (int j=0; j<4; ++j) {
			int nx = x + dx[j];
			int ny = y + dy[j];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n || map[nx][ny] == -1)
				continue;

			u.uni(map[x][y], map[nx][ny]);
		}
	}

	int ans = 0;
	while (1) {
		if (abs(u.p[u.find(0)]) >= k)
			break;

		int sz = que.size();
		for (int i=0; i<sz; ++i) {
			x = que.front() / MAX;
			y = que.front() % MAX;
			que.pop();

			for (int j=0; j<4; ++j) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n || map[nx][ny] != -1)
					continue;

				que.push(nx*MAX+ny);
				map[nx][ny] = map[x][y];

				for (int r=0; r<4; ++r) {
					int nnx = nx + dx[r];
					int nny = ny + dy[r];

					if (nnx < 0 || nnx >= n || nny < 0 || nny >= n || map[nnx][nny] == -1)
						continue;

					u.uni(map[nx][ny], map[nnx][nny]);
				}
			}
		}
		ans++;
	}
	cout << ans << '\n';

	return 0;
}
