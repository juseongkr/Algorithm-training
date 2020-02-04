#include <iostream>
using namespace std;
#define MAX 102

bool x, y;
int n, m, ymx, xmx;
char map[MAX][MAX];
int ver[MAX], hor[MAX];

int main()
{
	cin >> n >> m;
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=m; ++j)
			cin >> map[i][j];

	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j)
			ver[i] += map[i][j] == '#' ? 1 : 0;
		if (ver[i] == 1)
			y = true;
		ymx = max(ymx, ver[i]);
	}

	for (int i=1; i<=m; ++i) {
		for (int j=1; j<=n; ++j)
			hor[i] += map[j][i] == '#' ? 1 : 0;
		if (hor[i] == 1)
			x = true;
		xmx = max(xmx, hor[i]);
	}

	if (x) {
		for (int i=0; i<MAX; ++i) {
			if (ver[i] == xmx && ver[i+1] == 0) {
				cout << "UP\n";
				return 0;
			}
		}
		cout << "DOWN\n";
	}

	if (y) {
		for (int i=0; i<MAX; ++i) {
			if (hor[i] == ymx && hor[i+1] == 0) {
				cout << "LEFT\n";
				return 0;
			}
		}
		cout << "RIGHT\n";
	}

	return 0;
}
