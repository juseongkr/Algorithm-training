#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 101
const int INF = 1e9+7;

int n, m, a, b, c;
int map[MAX][MAX], p[MAX][MAX];
int dist[MAX];

void path(int x, int y)
{
	if (p[x][y] == -1) {
		cout << "0\n";
		return;
	}

	queue<int> que;
	que.push(x);

	while (x != y) {
		x = p[x][y];
		que.push(x);
	}

	cout << que.size() << " ";
	while (!que.empty()) {
		cout << que.front() << " ";
		que.pop();
	}
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			if (i == j)
				map[i][j] = 0;
			else
				map[i][j] = INF;
		}
	}

	memset(p, -1, sizeof(p));
	for (int i=0; i<m; ++i) {
		cin >> a >> b >> c;
		if (map[a][b] > c) {
			map[a][b] = c;
			p[a][b] = b;
		}
	}

	for (int k=1; k<=n; ++k) {
		for (int i=1; i<=n; ++i) {
			for (int j=1; j<=n; ++j) {
				if (map[i][j] > map[i][k] + map[k][j]) {
					map[i][j] = map[i][k] + map[k][j];
					p[i][j] = p[i][k];
				}
			}
		}
	}

	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			if (map[i][j] == INF)
				cout << "0 ";
			else
				cout << map[i][j] << " ";
		}
		cout << '\n';
	}

	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			if (i == j || map[i][j] == INF)
				cout << "0\n";
			else
				path(i, j);
		}
	}

	return 0;
}
