#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 101

int n, m;
long long ans;
long long s[MAX][MAX];

long long area(int x1, int y1, int x2, int y2)
{
	return s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1];
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			scanf("%1lld", &s[i][j]);
			s[i][j] += s[i][j-1] + s[i-1][j] - s[i-1][j-1];
		}
	}

	for (int i=1; i<n; ++i) {
		for (int j=1; j<m; ++j) {
			long long x = s[i][m] * area(i, 0, n, j) * area(i, j, n, m);
			long long y = s[n][j] * area(0, j, i, m) * area(i, j, n, m);
			long long z = s[i][j] * area(0, j, n, m) * area(i, 0, n, j);
			long long r = s[i][j] * area(0, j, i, m) * area(i, 0, n, m);
			ans = max(ans, max(x, max(y, max(z, r))));
		}
	}

	for (int i=1; i<n; ++i)
		for (int j=i+1; j<=n; ++j)
			ans = max(ans, s[i][m] * area(i, 0, j, m) * area(j, 0, n, m));

	for (int i=0; i<m; ++i)
		for (int j=i+1; j<=m; ++j)
			ans = max(ans, s[n][i] * area(0, i, n, j) * area(0, j, n, m));

	printf("%lld\n", ans);

	return 0;
}
