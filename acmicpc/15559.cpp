#include <iostream>
using namespace std;
#define MAX 1001

int n, m, ans, cur;
int visit[MAX][MAX];
char map[MAX][MAX];

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (visit[i][j])
				continue;

			cur++;
			int x = i, y = j;
			while (1) {
				if (visit[x][y])
					break;

				visit[x][y] = cur;
				if (map[x][y] == 'S')
					x++;
				else if (map[x][y] == 'E')
					y++;
				else if (map[x][y] == 'N')
					x--;
				else
					y--;
			}
			if (visit[x][y] == cur)
				ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}
