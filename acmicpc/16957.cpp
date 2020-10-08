#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 500
const int dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dy[8] = {1, 0, -1, 0, 1, 1, -1, -1};

int n, m;
int map[MAX][MAX], ans[MAX*MAX], p[MAX*MAX];

int find(int x)
{
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			int x = i;
			int y = j;
			for (int k=0; k<8; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					continue;

				if (map[x][y] > map[nx][ny]) {
					x = nx;
					y = ny;
				}
			}

			p[i*MAX+j] = x*MAX+y;
		}
	}

	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			ans[find(i*MAX+j)]++;

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j)
			cout << ans[i*MAX+j] << " ";
		cout << '\n';
	}

	return 0;
}
