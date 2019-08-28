#include <iostream>
using namespace std;
#define MAX 21

const int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
int num[MAX][MAX];
int dp[MAX][MAX][MAX][MAX][MAX];
int n, l;

int main()
{
	cin >> n >> l;
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			cin >> num[i][j];

	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			dp[1][i][j][i][j] = 1;

	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			for (int k=0; k<8; ++k) {
				int x = i + dx[k];
				int y = j + dy[k];

				if (x <= 0 || x > n || y <= 0 || y > n)
					continue;

				if (num[i][j] == num[x][y])
					dp[2][i][j][x][y]++;
			}
		}
	}

	for (int t=3; t<=l; ++t) {
		for (int i=1; i<=n; ++i) {
			for (int j=1; j<=n; ++j) {
				for (int i2=1; i2<=n; ++i2) {
					for (int j2=1; j2<=n; ++j2) {
						if (num[i][j] != num[i2][j2])
							continue;

						for (int k=0; k<8; ++k) {
							for (int k2=0; k2<8; ++k2) {
								int x = i + dx[k];
								int y = j + dy[k];
								int nx = i2 + dx[k2];
								int ny = j2 + dy[k2];

								if (x <= 0 || x > n || y <= 0 || y > n || nx <= 0 || nx > n || ny <= 0 || ny > n)
									continue;
								if (num[x][y] == num[nx][ny])
									dp[t][i][j][i2][j2] += dp[t-2][x][y][nx][ny];
							}
						}
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			for (int k=1; k<=n; ++k)
				for (int t=1; t<=n; ++t)
					ans += dp[l][i][j][k][t];

	cout << ans << '\n';

	return 0;
}
