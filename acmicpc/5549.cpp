#include <iostream>
using namespace std;
#define MAX 1002

int n, m, k, x, x2, y, y2;
int J[MAX][MAX], I[MAX][MAX], O[MAX][MAX];
char c;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			cin >> c;
			if (c == 'J')
				J[i][j]++;
			else if (c == 'O')
				O[i][j]++;
			else
				I[i][j]++;
		}
	}

	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			J[i][j] += J[i][j-1];
			O[i][j] += O[i][j-1];
			I[i][j] += I[i][j-1];
		}
	}

	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			J[i][j] += J[i-1][j];
			O[i][j] += O[i-1][j];
			I[i][j] += I[i-1][j];
		}
	}

	for (int i=0; i<k; ++i) {
		cin >> x >> y >> x2 >> y2;
		x--;
		y--;
		cout << J[x2][y2] - J[x][y2] - J[x2][y] + J[x][y] << ' ';
		cout << O[x2][y2] - O[x][y2] - O[x2][y] + O[x][y] << ' ';
		cout << I[x2][y2] - I[x][y2] - I[x2][y] + I[x][y] << '\n';
	}

	return 0;
}
