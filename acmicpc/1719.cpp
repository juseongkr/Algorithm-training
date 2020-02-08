#include <iostream>
using namespace std;
#define MAX 201
const int INF = 1e9+7;

int n, m, x, y, z;
int map[MAX][MAX], dist[MAX][MAX], ans[MAX][MAX];

int main()
{
	for (int i=0; i<MAX; ++i)
		for (int j=0; j<MAX; ++j)
			if (i != j)
				map[i][j] = dist[i][j] = INF;

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		x--;
		y--;
		map[x][y] = map[y][x] = dist[x][y] = dist[y][x] = min(map[x][y], z);
	}

	for (int k=0; k<n; ++k)
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (i == j)
				continue;
			for (int k=0; k<n; ++k) {
				if (i == k || map[i][k] == INF)
					continue;

				if (dist[i][j] == map[i][k] + dist[k][j]) {
					ans[i][j] = k+1;
					break;
				}
			}
		}
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (i == j)
				cout << "- ";
			else
				cout << ans[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}
