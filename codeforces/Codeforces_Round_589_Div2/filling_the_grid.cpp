#include <iostream>
#include <cmath>
using namespace std;
#define MAX 1001
const int MOD = 1e9+7;

int r[MAX], c[MAX];
int map[MAX][MAX];

int main()
{
	int n, m;

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> r[i];

	for (int i=0; i<m; ++i)
		cin >> c[i];

	for (int i=0; i<n; ++i) {
		for (int j=0; j<=r[i]; ++j) {
			if (j == r[i]) {
				if (map[i][j] == 1) {
					cout << "0\n";
					return 0;
				}
				map[i][j] = 2;
			} else {
				if (map[i][j] == 2) {
					cout << "0\n";
					return 0;
				}
				map[i][j] = 1;
			}
		}
	}

	for (int i=0; i<m; ++i) {
		for (int j=0; j<=c[i]; ++j) {
			if (j == c[i]) {
				if (map[j][i] == 1) {
					cout << "0\n";
					return 0;
				}
				map[j][i] = 2;
			} else {
				if (map[j][i] == 2) {
					cout << "0\n";
					return 0;
				}
				map[j][i] = 1;
			}
		}
	}

	int cnt = 0;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (map[i][j] == 0)
				cnt++;

	if (cnt) {
		long long ans = 1;
		for (int i=0; i<cnt; ++i)
			ans = (ans * 2) % MOD;
		cout << ans << '\n';
	} else {
		cout << "1\n";
	}

	return 0;
}
