#include <iostream>
using namespace std;
#define MAX 102

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
int block[MAX][MAX];
int n, m;

int main()
{
	cin >> n >> m;
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=m; ++j)
			cin >> block[i][j];

	int ans = n * m * 2;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			for (int k=0; k<4; ++k) {
				int diff = block[i][j] - block[i+dy[k]][j+dx[k]];
				if (diff >= 0)
					ans += diff;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
