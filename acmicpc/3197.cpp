#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1501
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

vector<int> swan;
char map[MAX][MAX];

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

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, m;

	cin >> n >> m;
	UnionFind u = UnionFind(n*MAX+m);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'L')
				swan.push_back(i*MAX+j);
		}
	}

	queue<int> que;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (map[i][j] == 'X')
				continue;

			for (int k=0; k<4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == 'X')
					continue;

				u.uni(i*MAX+j, nx*MAX+ny);
			}
			que.push(i*MAX+j);
		}
	}
	
	int ans = 0;
	while (1) {
		if (u.find(swan[0]) == u.find(swan[1])) {
			cout << ans << '\n';
			break;
		}

		int len = que.size();
		for (int i=0; i<len; ++i) {
			int x = que.front() / MAX;
			int y = que.front() % MAX;
			que.pop();

			for (int k=0; k<4; ++k) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] != 'X')
					continue;

				map[nx][ny] = '.';
				u.uni(x*MAX+y, nx*MAX+ny);
				que.push(nx*MAX+ny);

				for (int t=0; t<4; ++t) {
					int nnx = nx + dx[t];
					int nny = ny + dy[t];

					if (nnx < 0 || nnx >= n || nny < 0 || nny >= m || map[nnx][nny] == 'X')
						continue;

					u.uni(nx*MAX+ny, nnx*MAX+nny);
				}
			}
		}
		ans++;
	}

	return 0;
}
