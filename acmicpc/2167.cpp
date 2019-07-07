#include <iostream>
using namespace std;
#define MAX 302

int main()
{
	int num[MAX][MAX], psum[MAX][MAX];
	int n, m, k, a, b, x, y;

	cin >> n >> m;
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=m; ++j)
			cin >> num[i][j];

	for (int i=1; i<=n+1; ++i)
		for (int j=1; j<=m+1; ++j)
			psum[i][j] = psum[i][j-1] + psum[i-1][j] - psum[i-1][j-1] + num[i-1][j-1];

	cin >> k;
	for (int i=0; i<k; ++i) {
		cin >> a >> b >> x >> y;
		cout << psum[x+1][y+1] + psum[a][b] - psum[a][y+1] - psum[x+1][b] << '\n';
	}

	return 0;
}
